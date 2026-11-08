--- qimgv/main.cpp.orig	2025-09-05 05:00:37 UTC
+++ qimgv/main.cpp
@@ -84,7 +84,7 @@ int main(int argc, char *argv[]) {
     QCoreApplication::setApplicationName("qimgv");
     QCoreApplication::setApplicationVersion(appVersion.toString());
     QApplication::setEffectEnabled(Qt::UI_AnimateCombo, false);
-    QGuiApplication::setDesktopFileName(QCoreApplication::applicationName() + ".desktop");
+    QGuiApplication::setDesktopFileName(QCoreApplication::applicationName());
 
     // needed for mpv
 #ifndef _MSC_VER
