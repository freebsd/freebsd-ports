--- win/Qt/qt_win.cpp.orig	Tue Oct 14 11:29:05 2003
+++ win/Qt/qt_win.cpp	Tue Oct 14 11:29:52 2003
@@ -75,6 +75,11 @@
 #undef yn
 #endif
 
+#ifdef Invisible
+/* Invisible was added to an enum in Qt 3.2, #defined in youprop.h */
+#undef Invisible
+#endif
+
 #include "qt_win.h"
 #include <qregexp.h>
 #include <qpainter.h>
