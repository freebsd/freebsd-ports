--- src/svnqt/wc.cpp.orig	Sun Jul 23 03:30:36 2006
+++ src/svnqt/wc.cpp	Sun Jul 23 03:36:09 2006
@@ -113,7 +113,7 @@
     QString result = "";
     const svn_wc_entry_t *entry;
     entry = getEntry( path );
-    result = entry?QString::FROMUTF8(entry->repos):"";
+    result = entry ? QString::FROMUTF8(entry->repos) : QString::fromLatin1("");
 
     return result;
   }
