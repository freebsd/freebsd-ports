--- win/Qt/qt_win.cpp.orig	2021-03-22 22:28:14 UTC
+++ win/Qt/qt_win.cpp
@@ -57,6 +57,11 @@ extern "C" {
 #endif
 #include "qt_post.h"
 
+#ifdef Invisible
+/* Invisible was added to an enum in Qt 3.2, #defined in youprop.h */
+#undef Invisible
+#endif
+
 // Many of these headers are not needed here.  It's a holdover
 // from when most of the Qt code was in one big file.
 #include "qt_win.h"
