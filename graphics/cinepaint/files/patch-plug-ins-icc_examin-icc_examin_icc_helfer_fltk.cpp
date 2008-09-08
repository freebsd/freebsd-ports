--- plug-ins/icc_examin/icc_examin/icc_helfer_fltk.cpp.orig	2008-09-03 02:07:08.000000000 +0200
+++ plug-ins/icc_examin/icc_examin/icc_helfer_fltk.cpp	2008-09-03 02:08:02.000000000 +0200
@@ -226,7 +226,7 @@
 
   int  awake(void)
   {
-    Fl::awake(0);
+    Fl::awake((void *)0);
     return 0;
   }
   int  leerWait(void) { return 0; }
