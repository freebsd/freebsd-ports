--- src/w32.cpp.orig	2015-03-28 15:21:41 UTC
+++ src/w32.cpp
@@ -21,7 +21,7 @@
 #include <ccaudio2-config.h>
 #include <math.h>
 #ifdef  HAVE_ENDIAN_H
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 #define MAX_DEVICES 1
 
