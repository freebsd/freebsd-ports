--- source/lib/lib.h.orig	2013-09-17 20:41:12.887277235 +0200
+++ source/lib/lib.h	2013-09-17 20:44:34.202282356 +0200
@@ -63,6 +63,7 @@
 #include <cmath>	// fabsf
 #include <limits>	// numeric_limits
 #include <stdexcept>	// out_of_range
+#include <algorithm>	// std::min, std::max
 
 template<typename T>
 T Clamp(T val, T min, T max)
