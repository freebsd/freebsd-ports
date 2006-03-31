--- src/matrix.c.orig	Tue Nov 22 07:30:44 2005
+++ src/matrix.c	Mon Mar 20 14:13:22 2006
@@ -35,6 +35,11 @@
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
