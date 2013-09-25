--- src/utils.h.orig	2013-09-21 17:20:43.538723086 +0000
+++ src/utils.h	2013-09-21 17:21:02.622721058 +0000
@@ -30,6 +30,7 @@
 #include <stdint.h>
 #include <limits>
 #include <iterator>
+#include <algorithm>    // std::fill
 
 #ifndef HAVE_ROUND
 static inline double round(double x)
