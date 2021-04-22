https://github.com/spring/spring/pull/555

--- rts/System/SpringHashMap.hpp.orig	2021-01-01 16:12:22 UTC
+++ rts/System/SpringHashMap.hpp
@@ -9,6 +9,7 @@
 #include <cstdlib>
 #include <iterator>
 #include <utility>
+#include <algorithm>
 
 #define DCHECK_EQ_F(a, b)
 #define DCHECK_LT_F(a, b)
