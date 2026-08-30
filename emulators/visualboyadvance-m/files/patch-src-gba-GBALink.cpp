--- src/gba/GBALink.cpp.orig	2026-08-30 14:41:40 UTC
+++ src/gba/GBALink.cpp
@@ -2,9 +2,10 @@
 // with major changes by tjm
 #include <string.h>
 #include <stdio.h>
+#include <sys/param.h>
 
 // malloc.h does not seem to exist on Mac OS 10.7
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
@@ -65,12 +66,6 @@ BLARGG_DEF_MIN_MAX(double)
 BLARGG_DEF_MIN_MAX(unsigned long)
 BLARGG_DEF_MIN_MAX(float)
 BLARGG_DEF_MIN_MAX(double)
-
-#undef  min
-#define min blargg_min
-
-#undef  max
-#define max blargg_max
 
 // Joybus
 bool gba_joybus_enabled = false;
