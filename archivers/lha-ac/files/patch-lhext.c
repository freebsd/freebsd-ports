--- src/lhext.c.orig	Thu Sep 23 09:01:34 2004
+++ src/lhext.c	Thu Sep 23 09:01:34 2004
@@ -88,7 +88,8 @@
     register char  *p;
 
     /* make parent directory name into PATH for recursive call */
-    strcpy(path, name);
+    memset(path, 0, sizeof(path));
+    strncpy(path, name, sizeof(path)-1);
     for (p = path + strlen(path); p > path; p--)
         if (p[-1] == '/') {
             *--p = '\0';
@@ -249,8 +250,10 @@
 
     if (extract_directory)
         xsnprintf(name, sizeof(name), "%s/%s", extract_directory, q);
-    else
-        strcpy(name, q);
+    else {
+        strncpy(name, q, sizeof(name));
+        name[sizeof(name) - 1] = '\0';
+    }
 
 
     /* LZHDIRS_METHODを持つヘッダをチェックする */
