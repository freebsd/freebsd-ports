--- fetcher.cc.orig	Sun Jan 25 16:55:21 2004
+++ fetcher.cc	Wed Feb 11 18:34:39 2004
@@ -200,8 +200,12 @@
         return identified;
 
     // Erase the first occurrence of the artist
-    list<string>::iterator i = find(file_parts.begin(), file_parts.end(),
-            artist);
+    list<string>::iterator i = file_parts.begin();
+    while (i != file_parts.end()) {
+	if (*i == artist)
+	    break;
+	i++;
+    }
     if (i != file_parts.end())
         file_parts.erase(i);
 
