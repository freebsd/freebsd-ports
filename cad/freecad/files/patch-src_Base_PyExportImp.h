--- ./src/Base/PyExportImp.h.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/PyExportImp.h	Sun Apr 22 11:33:01 2007
@@ -33,6 +33,13 @@
 // needed header
 #undef slots
 #	include <Python.h>
+#undef isspace
+#undef isupper
+#undef islower
+#undef isalpha
+#undef isalnum
+#undef toupper
+#undef tolower
 #define slots
 #include <iostream>
 
