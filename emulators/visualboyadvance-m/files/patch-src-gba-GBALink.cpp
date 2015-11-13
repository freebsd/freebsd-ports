--- src/gba/GBALink.cpp.orig	2014-04-29 17:12:28.260667843 -0700
+++ src/gba/GBALink.cpp	2014-04-29 17:15:31.307655026 -0700
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
