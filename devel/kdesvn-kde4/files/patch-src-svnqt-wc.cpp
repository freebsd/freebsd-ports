--- src/svnqt/wc.cpp.orig	Sat Apr 29 00:58:38 2006
+++ src/svnqt/wc.cpp	Sat Apr 29 00:59:21 2006
@@ -96,7 +96,7 @@
     if (error!=0) {
         throw ClientException(error);
     }
-    result = entry?QString::fromUtf8(entry->url):"";
+    result = entry ? QString::fromUtf8(entry->url) : QString::fromLatin1("");
 
     return result;
   }
