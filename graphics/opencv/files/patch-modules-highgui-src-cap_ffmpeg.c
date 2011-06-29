--- modules/highgui/src/cap_ffmpeg.cpp.orig	2011-06-21 15:24:06.000000000 +0200
+++ modules/highgui/src/cap_ffmpeg.cpp	2011-06-27 08:36:37.096041264 +0200
@@ -53,7 +53,8 @@
 #define UINT64_C
 #define __STDC_CONSTANT_MACROS
 // force re-inclusion of stdint.h to get INT64_C macro
-#undef _STDINT_H
+#undef _SYS_STDINT_H_
+#undef _MACHINE__STDINT_H_
 #include <stdint.h>
 #endif
 #include <errno.h>
