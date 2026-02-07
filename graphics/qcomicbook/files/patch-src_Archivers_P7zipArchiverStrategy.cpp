--- src/Archivers/P7zipArchiverStrategy.cpp.orig	2016-11-22 17:45:10 UTC
+++ src/Archivers/P7zipArchiverStrategy.cpp
@@ -30,7 +30,7 @@ void P7zipArchiverStrategy::configure()
     addExtension(".7z");
     addExtension(".cb7");
 
-    setExecutables("7z", "7zr");
+    setExecutables("7z", "7zz");
 
     if (which("7z") != QString::null)
     {
@@ -38,10 +38,10 @@ void P7zipArchiverStrategy::configure()
         setListArguments("7z l @F");
         setSupported();
     }
-    else if (which("7zr") != QString::null)
+    else if (which("7zz") != QString::null)
     {
-        setExtractArguments("7zr x @F");
-        setListArguments("7zr l @F");
+        setExtractArguments("7zz x @F");
+        setListArguments("7zz l @F");
         setSupported();
     }
 }
