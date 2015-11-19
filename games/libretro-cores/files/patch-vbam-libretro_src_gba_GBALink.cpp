--- vbam-libretro/src/gba/GBALink.cpp.orig	2015-11-08 20:19:43 UTC
+++ vbam-libretro/src/gba/GBALink.cpp
@@ -4,11 +4,7 @@
 #include <stdio.h>
 
 // malloc.h does not seem to exist on Mac OS 10.7
-#ifdef __APPLE__
 #include <stdlib.h>
-#else
-#include <malloc.h>
-#endif
 
 int vbaid = 0;
 const char *MakeInstanceFilename(const char *Input)
