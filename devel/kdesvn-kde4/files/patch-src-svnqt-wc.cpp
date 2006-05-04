--- src/svnqt/wc.cpp.orig	Sat Apr  8 06:36:12 2006
+++ src/svnqt/wc.cpp	Wed May  3 19:53:42 2006
@@ -103,7 +103,7 @@
     QString result = "";
     const svn_wc_entry_t *entry;
     entry = getEntry( path );
-    result = entry?QString::fromUtf8(entry->url):"";
+    result = entry ? QString::fromUtf8(entry->url) : QString::fromLatin1("");
     
     return result;
   }
