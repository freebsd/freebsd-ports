--- ./main.cpp.orig	Mon Mar 19 15:56:21 2007
+++ ./main.cpp	Tue Jun 12 13:17:03 2007
@@ -45,7 +45,7 @@
         translator.load(path);
     else
     {
-        path = QCoreApplication::applicationDirPath()+"/../translations/qtemu_" + locale + ".qm";
+        path = QCoreApplication::applicationDirPath()+"/../share/qtemu/translations/qtemu_" + locale + ".qm";
         if (QFile::exists(path))
             translator.load(path);
     }
