--- src/opengl.cc.orig	Sat Jun 12 11:19:02 2004
+++ src/opengl.cc	Sun May 27 20:26:03 2007
@@ -396,12 +396,11 @@
 /****************************************************************************
 *
 ****************************************************************************/
-PRIVATE void on_exit_h(int code, void *arg)
+PRIVATE void on_exit_h()
 {
   free_textures();
 
-  if(!code)
-    printf("See ya\n");
+  printf("See ya\n");
 }
 
 /*
@@ -578,7 +577,7 @@
 {
   int x, fs_f = 0;
 
-  on_exit(on_exit_h, 0);
+  atexit(on_exit_h);
   glutInit(&argc, argv);
   glutInitDisplayMode(mode);
 
