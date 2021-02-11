--- common/fractals.c.orig	2015-01-19 18:35:16 UTC
+++ common/fractals.c
@@ -43,7 +43,7 @@ an appropriate setup, per_image, per_pixel, and orbit 
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
@@ -3437,7 +3437,7 @@ MandelbrotMix4fpFractal(void) /* from formula by Jim M
 #undef K
 #undef L
 
-double b_const;
+extern double b_const;
 
 int DivideBrot5Setup(void)
 {
