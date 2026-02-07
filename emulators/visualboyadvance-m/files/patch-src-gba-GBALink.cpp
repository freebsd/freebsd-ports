--- src/gba/GBALink.cpp.orig	2016-08-13 15:20:47 UTC
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
