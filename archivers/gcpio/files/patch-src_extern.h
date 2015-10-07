--- src/extern.h.orig	2015-09-12 10:57:30 UTC
+++ src/extern.h
@@ -96,6 +96,7 @@ extern char input_is_special;
 extern char output_is_special;
 extern char input_is_seekable;
 extern char output_is_seekable;
+extern bool extract_over_symlinks;
 extern int (*xstat) ();
 extern void (*copy_function) ();
 extern char *change_directory_option;
