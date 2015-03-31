--- src/extern.h.orig	2010-02-15 10:02:23 UTC
+++ src/extern.h
@@ -95,6 +95,7 @@ extern char input_is_special;
 extern char output_is_special;
 extern char input_is_seekable;
 extern char output_is_seekable;
+extern bool extract_over_symlinks;
 extern int (*xstat) ();
 extern void (*copy_function) ();
 
