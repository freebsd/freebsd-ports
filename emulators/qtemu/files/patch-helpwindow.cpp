--- ./helpwindow.cpp.orig	Mon Mar 19 15:56:21 2007
+++ ./helpwindow.cpp	Tue Jun 12 13:23:44 2007
@@ -72,7 +72,7 @@
             return testUrl;
     
         //check for case when qtemu executable is in bin/ (installed on linux)
-        testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../help/" + locale + "/main.htm");
+        testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../share/doc/qtemu/" + locale + "/main.htm");
         if (QFile::exists(testUrl.toString()))
             return testUrl;
     }
@@ -88,7 +88,7 @@
         return testUrl;
 
     //check for case when qtemu executable is in bin/ (installed on linux)
-    testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../help/main.htm");
+    testUrl = QUrl(QCoreApplication::applicationDirPath()+"/../share/doc/qtemu/main.htm");
     if (QFile::exists(testUrl.toString()))
         return testUrl;
 
