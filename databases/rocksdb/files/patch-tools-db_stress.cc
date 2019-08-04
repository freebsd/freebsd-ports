tools/db_stress.cc:3613:33: error: implicit instantiation of undefined template 'std::__1::array<std::__1::basic_string<char>, 10>'
    std::array<std::string, 10> keys = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
                                ^
/usr/include/c++/v1/__tuple:223:64: note: template is declared here
template <class _Tp, size_t _Size> struct _LIBCPP_TEMPLATE_VIS array;
                                                               ^
tools/db_stress.cc:3896:30: error: implicit conversion loses integer precision: 'std::__1::vector<long, std::__1::allocator<long> >::size_type' (aka 'unsigned long') to 'int' [-Werror,-Wshorten-64-to-32]
    int num_keys = rand_keys.size();
        ~~~~~~~~   ~~~~~~~~~~^~~~~~
2 errors generated.

--- tools/db_stress.cc.orig	2019-06-07 23:23:07 UTC
+++ tools/db_stress.cc
@@ -38,6 +38,7 @@ int main() {
 #include <stdlib.h>
 #include <sys/types.h>
 #include <algorithm>
+#include <array>
 #include <chrono>
 #include <exception>
 #include <queue>
@@ -3893,7 +3894,7 @@ class AtomicFlushStressTest : public Str
       const ReadOptions& read_opts,
       const std::vector<int>& rand_column_families,
       const std::vector<int64_t>& rand_keys) {
-    int num_keys = rand_keys.size();
+    size_t num_keys = rand_keys.size();
     std::vector<std::string> key_str;
     std::vector<Slice> keys;
     keys.reserve(num_keys);
@@ -3902,7 +3903,7 @@ class AtomicFlushStressTest : public Str
     std::vector<Status> statuses(num_keys);
     ColumnFamilyHandle* cfh = column_families_[rand_column_families[0]];
 
-    for (int i = 0; i < num_keys; ++i) {
+    for (size_t i = 0; i < num_keys; ++i) {
       key_str.emplace_back(Key(rand_keys[i]));
       keys.emplace_back(key_str.back());
     }
