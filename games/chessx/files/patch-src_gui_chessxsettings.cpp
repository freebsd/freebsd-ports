--- src/gui/chessxsettings.cpp.orig	2023-05-08 20:22:12 UTC
+++ src/gui/chessxsettings.cpp
@@ -19,11 +19,11 @@
 #include <QWidget>
 #include <QMainWindow>
 #include <QSplitter>
+#ifdef USE_SPEECH
 #include <QTextToSpeech>
+#endif
 #include <QLayout>
-
 using namespace chessx;
-
 #if defined(_MSC_VER) && defined(_DEBUG)
 #define DEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
 #define new DEBUG_NEW
