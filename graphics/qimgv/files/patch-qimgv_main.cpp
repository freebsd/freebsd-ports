--- qimgv/main.cpp.orig	2025-09-05 05:00:37 UTC
+++ qimgv/main.cpp
@@ -84,7 +84,12 @@ int main(int argc, char *argv[]) {
     QCoreApplication::setApplicationName("qimgv");
     QCoreApplication::setApplicationVersion(appVersion.toString());
     QApplication::setEffectEnabled(Qt::UI_AnimateCombo, false);
+
+# if (QT_VERSION_MAJOR == 6)
+    QGuiApplication::setDesktopFileName(QCoreApplication::applicationName());
+# else
     QGuiApplication::setDesktopFileName(QCoreApplication::applicationName() + ".desktop");
+#endif
 
     // needed for mpv
 #ifndef _MSC_VER
