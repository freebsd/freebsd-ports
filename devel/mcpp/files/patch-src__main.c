--- ./src/main.c.orig	2008-11-05 09:34:46.000000000 +0100
+++ ./src/main.c	2011-03-30 19:57:37.000000000 +0200
@@ -326,6 +326,8 @@
             = FALSE;
     option_flags.trig = TRIGRAPHS_INIT;
     option_flags.dig = DIGRAPHS_INIT;
+    sh_file = NULL;
+    sh_line = 0;
 }
 
 int     mcpp_lib_main
