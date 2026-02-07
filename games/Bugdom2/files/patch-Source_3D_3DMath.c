--- Source/3D/3DMath.c.orig	2024-04-18 14:30:18 UTC
+++ Source/3D/3DMath.c
@@ -12,6 +12,9 @@
 
 #include "game.h"
 
+#if defined(__VEC__)
+#include <altivec.h>
+#endif
 
 /****************************/
 /*    PROTOTYPES            */
