--- qterm/qtermwindow.h.orig	Mon Jul 10 15:36:12 2006
+++ qterm/qtermwindow.h	Thu Jul 27 17:39:46 2006
@@ -10,6 +10,14 @@
 #include <Python.h>
 #endif
 
+#undef isalnum
+#undef isalpha
+#undef islower
+#undef isspace
+#undef isupper
+#undef tolower
+#undef toupper
+
 #include <qmainwindow.h>
 #include <qcursor.h>
 
