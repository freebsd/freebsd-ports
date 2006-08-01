--- qterm/main.cpp.orig	Mon Jul 10 15:36:13 2006
+++ qterm/main.cpp	Thu Jul 27 17:55:53 2006
@@ -16,6 +16,15 @@
 #ifdef HAVE_PYTHON
 #include <Python.h>
 #endif
+
+#undef isalnum
+#undef isalpha
+#undef islower
+#undef isspace
+#undef isupper
+#undef tolower
+#undef toupper
+
 #include <qpixmap.h>
 #include <qstringlist.h>
 #include <qapplication.h>
