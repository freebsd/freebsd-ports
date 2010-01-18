--- src/highgui/cvcap_ffmpeg.cpp.orig	2009-11-25 03:11:36.744288703 +0000
+++ src/highgui/cvcap_ffmpeg.cpp	2009-11-25 03:13:37.172158178 +0000
@@ -52,7 +52,8 @@
 #define INT64_C
 #define __STDC_CONSTANT_MACROS
 // force re-inclusion of stdint.h to get INT64_C macro
-#undef _STDINT_H
+#undef _SYS_STDINT_H_
+#undef _MACHINE__STDINT_H_
 #include <stdint.h>
 #endif
 #include <errno.h>
