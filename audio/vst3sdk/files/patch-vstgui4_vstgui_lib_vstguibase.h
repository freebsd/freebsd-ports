--- vstgui4/vstgui/lib/vstguibase.h.orig	2021-03-22 20:04:22 UTC
+++ vstgui4/vstgui/lib/vstguibase.h
@@ -134,7 +134,7 @@
 	using std::min;
 	using std::max;
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #include <cstdint>
     #include <type_traits>
     #include <algorithm>
