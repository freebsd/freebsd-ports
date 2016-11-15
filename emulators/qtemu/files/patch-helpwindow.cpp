--- helpwindow.cpp.orig	2007-11-12 19:31:00 UTC
+++ helpwindow.cpp
@@ -80,7 +80,7 @@ QUrl HelpWindow::getHelpFile()
             return testUrl;
     
         //check for case when qtemu executable is in bin/ (installed on linux)
-        testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../help/" + locale + "/main.htm");
+        testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../share/doc/qtemu/" + locale + "/main.htm");
         if (QFile::exists(testUrl.toString()))
             return testUrl;
     }
@@ -96,7 +96,7 @@ QUrl HelpWindow::getHelpFile()
         return testUrl;
 
     //check for case when qtemu executable is in bin/ (installed on linux)
-    testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../help/main.htm");
+    testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../share/doc/qtemu/main.htm");
     if (QFile::exists(testUrl.toString()))
         return testUrl;
 
