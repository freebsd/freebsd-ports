--- main.cpp.orig	2007-11-12 19:31:00 UTC
+++ main.cpp
@@ -45,7 +45,7 @@ int main(int argc, char *argv[])
         translator.load(path);
     else
     {
-        path = QCoreApplication::applicationDirPath()+"/../translations/qtemu_" + locale + ".qm";
+        path = QCoreApplication::applicationDirPath()+"/../share/qtemu/translations/qtemu_" + locale + ".qm";
         if (QFile::exists(path))
             translator.load(path);
     }
