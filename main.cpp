#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<pair<int,int>, int> seen;
        for (auto& dom : dominoes) {
            int a = dom[0];
            int b = dom[1];
            pair<int,int> p = a > b ? make_pair(a, b) : make_pair(b, a);
            count += seen[p];
            ++seen[p];
        }
        return count;
    }
};


void test1() {
    vector<int> v1{1,2,3,4,5,6,7,8};

    vector<vector<int>> v2{
            vector<int>{1, 2},
            vector<int>{2, 1},
            vector<int>{3, 4},
            vector<int>{5, 6}
    };

    vector<vector<int>> v3{
            vector<int>{1, 2},
            vector<int>{2, 1},
            vector<int>{1, 1},
            vector<int>{1, 2},
            vector<int>{3, 4},
            vector<int>{5, 6}
    };

    vector<vector<int>> v4{
            vector<int>{1, 1},
            vector<int>{2, 2},
            vector<int>{1, 1},
            vector<int>{1, 2},
            vector<int>{1, 2},
            vector<int>{1, 1}
    };
    cout << "1 ? " << Solution().numEquivDominoPairs(v2) << endl;
    cout << "3 ? " << Solution().numEquivDominoPairs(v3) << endl;
    cout << "4 ? " << Solution().numEquivDominoPairs(v4) << endl;
}

void test2() {

}

void test3() {

}