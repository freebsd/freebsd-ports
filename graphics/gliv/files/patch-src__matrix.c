--- src/matrix.c.orig	2010-11-07 19:22:01 UTC
+++ src/matrix.c
@@ -35,6 +35,11 @@ extern rt_struct *rt;
 extern options_struct *options;
 extern GlivImage *current_image;
 
+#if !defined(INFINITY)
+#define HUGE_VALF (float)HUGE_VAL
+#define INFINITY HUGE_VALF
+#endif
+
 /*
  * OpenGL uses a transposed matrix, we use a 'normal' one,
  * we transpose it just before glLoadMatrix().
