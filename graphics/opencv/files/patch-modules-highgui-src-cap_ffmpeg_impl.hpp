--- modules/highgui/src/cap_ffmpeg_impl.hpp.orig	2011-07-11 09:39:11.188904113 +0200
+++ modules/highgui/src/cap_ffmpeg_impl.hpp	2011-07-11 09:39:41.732624055 +0200
@@ -57,7 +57,8 @@
 #define UINT64_C
 #define __STDC_CONSTANT_MACROS
 // force re-inclusion of stdint.h to get INT64_C macro
-#undef _STDINT_H
+#undef _SYS_STDINT_H_
+#undef _MACHINE__STDINT_H_
 #include <stdint.h>
 #endif
 #include <errno.h>
