--- cgx_2.22/src/extUtil.h.orig	2024-10-21 22:22:47 UTC
+++ cgx_2.22/src/extUtil.h
@@ -37,7 +37,7 @@ void printf_fflush(const char *fmt,...);
 }
   #endif
 #else
-  #include <GL/glut_cgx.h>
+  #include <GL/glut.h>
 #endif
 
 #define     PI          3.14159265358979323846264338327950288
