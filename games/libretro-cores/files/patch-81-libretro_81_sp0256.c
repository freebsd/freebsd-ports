--- 81-libretro/81/sp0256.c.orig	2016-11-09 04:30:27 UTC
+++ 81-libretro/81/sp0256.c
@@ -1,6 +1,6 @@
 #include <stdio.h>
 #if !defined(__CELLOS_LV2__) && !defined(__APPLE__)
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #include <string.h>
 
