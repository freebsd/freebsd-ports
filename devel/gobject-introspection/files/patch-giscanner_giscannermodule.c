--- giscanner/giscannermodule.c.orig	2009-12-01 02:49:21.000000000 -0500
+++ giscanner/giscannermodule.c	2009-12-01 02:49:34.000000000 -0500
@@ -23,6 +23,7 @@
 #  include "config.h"
 #endif
 #include "sourcescanner.h"
+#include "grealpath.h"
 #include <Python.h>
 
 #ifdef _WIN32
@@ -335,7 +336,7 @@ pygi_source_scanner_append_filename (PyG
     return NULL;
 
   self->scanner->filenames = g_list_append (self->scanner->filenames,
-					    g_strdup (filename));
+					    g_realpath (filename));
   
   Py_INCREF (Py_None);
   return Py_None;
