--- src/draw.c.orig	Thu Oct 16 08:13:22 2003
+++ src/draw.c	Wed Jul 14 14:20:17 2004
@@ -25,9 +25,9 @@
  */
 #include "pygame.h"
 #include <math.h>
+#include <sys/param.h>
 
-#ifdef _MSC_VER
-#pragma warning (disable:4244)
+#if __FreeBSD_version < 502119
 
 float trunc(float d)
 {
