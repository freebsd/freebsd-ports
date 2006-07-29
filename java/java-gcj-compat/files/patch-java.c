--- java.c~	Sat Jul 29 21:29:35 2006
+++ java.c	Sat Jul 29 21:29:52 2006
@@ -103,7 +103,7 @@
 
   free (newpath);
 
-  error_code = execv (GCJ_BIN_DIR "/gij", set_java_ext_dir (argc, argv));
+  error_code = execv (GCJ_BIN_DIR "/gij%%GCCSUFFIX%%", set_java_ext_dir (argc, argv));
 
   fprintf (stderr, "error spawning gij\n");
 
