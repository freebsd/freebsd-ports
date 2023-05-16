--- win/Qt/qt_bind.cpp.orig	2023-06-05 12:34:50 UTC
+++ win/Qt/qt_bind.cpp
@@ -11,7 +11,6 @@ extern "C" {
 #include "qt_pre.h"
 #include <QtGui/QtGui>
 #include <QtCore/QStringList>
-#if defined(USER_SOUNDS) && !defined(QT_NO_SOUND)
 #if QT_VERSION < 0x050000
 #include <QtGui/QSoundEffect>
 #elif QT_VERSION < 0x060000
@@ -22,7 +21,6 @@ extern "C" {
 #include <QtWidgets/QtWidgets>
 #include <QSoundEffect>
 #endif  /* QT_VERSION */
-#endif /* USER_SOUNDS && !QT_NO_SOUND */
 #include "qt_post.h"
 #include "qt_bind.h"
 #include "qt_click.h"
