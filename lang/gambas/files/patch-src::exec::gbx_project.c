--- ./src/exec/gbx_project.c.orig	Sun Jun  6 10:34:28 2004
+++ ./src/exec/gbx_project.c	Fri Jun 25 21:11:03 2004
@@ -263,7 +263,7 @@
 
   STRING_new(&PROJECT_exec_path, FILE_get_dir(FILE_get_dir(path)), -1);
 
-  STRING_new(&PROJECT_lib_path, FILE_cat(PROJECT_exec_path, "lib/gambas", NULL), 0);
+  STRING_new(&PROJECT_lib_path, "%%PREFIX%%/lib/gambas", 0);
 
   /* fichier projet */
 
