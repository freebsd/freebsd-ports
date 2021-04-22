https://github.com/spring/spring/pull/555

--- rts/System/SpringHashSet.hpp.orig	2021-01-01 16:12:22 UTC
+++ rts/System/SpringHashSet.hpp
@@ -9,6 +9,7 @@
 #include <cstdlib> // malloc
 #include <iterator>
 #include <utility>
+#include <algorithm> // fill_n
 
 #define DCHECK_EQ_F(a, b)
 #define DCHECK_LT_F(a, b)
