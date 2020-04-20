--- vst/external/VST_SDK/VST3_SDK/vstgui4/vstgui/lib/vstguibase.h.orig	2020-04-20 01:31:17 UTC
+++ vst/external/VST_SDK/VST3_SDK/vstgui4/vstgui/lib/vstguibase.h
@@ -134,7 +134,7 @@
 	using std::min;
 	using std::max;
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
     #include <cstdint>
     #include <type_traits>
     #include <algorithm>
