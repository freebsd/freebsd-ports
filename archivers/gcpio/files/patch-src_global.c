--- src/global.c.orig	2010-02-12 10:19:23 UTC
+++ src/global.c
@@ -187,6 +187,9 @@ bool to_stdout_option = false;
 /* The name this program was run with.  */
 char *program_name;
 
+/* Extract files over symbolic links */
+bool extract_over_symlinks;
+
 /* A pointer to either lstat or stat, depending on whether
    dereferencing of symlinks is done for input files.  */
 int (*xstat) ();
