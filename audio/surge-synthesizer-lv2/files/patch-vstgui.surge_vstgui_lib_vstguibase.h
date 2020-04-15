--- vstgui.surge/vstgui/lib/vstguibase.h.orig	2020-04-15 17:36:33 UTC
+++ vstgui.surge/vstgui/lib/vstguibase.h
@@ -121,7 +121,7 @@
 	using std::min;
 	using std::max;
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
     #include <cstdint>
     #include <type_traits>
     #include <algorithm>
