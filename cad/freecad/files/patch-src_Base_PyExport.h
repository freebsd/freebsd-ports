--- ./src/Base/PyExport.h.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/PyExport.h	Sun Apr 22 10:49:49 2007
@@ -19,6 +19,13 @@
 
 #undef slots
 #include <Python.h>
+#undef isspace
+#undef isupper
+#undef islower
+#undef isalpha
+#undef isalnum
+#undef toupper
+#undef tolower
 #define slots
 //#include <iostream>
 //#include <typeinfo>
