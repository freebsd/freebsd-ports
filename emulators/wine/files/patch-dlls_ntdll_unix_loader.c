--- UTC
--- dlls/ntdll/unix/loader.c.orig	2024-01-16 20:55:47
+++ dlls/ntdll/unix/loader.c	2024-05-10 07:03:04
@@ -480,6 +480,21 @@
 
     if (machine == current_machine) return NULL;
 
+    char* wineserver_path = getenv("WINESERVER");
+    if (wineserver_path != NULL && wineserver_path[0] == '/') {
+        char* s = remove_tail(wineserver_path, "server");
+        if (s != NULL) {
+            if (machine == IMAGE_FILE_MACHINE_AMD64) {
+                ret = malloc(strlen(s) + 3);
+                strcpy(ret, s);
+                strcat(ret, "64");
+            } else {
+                ret = s;
+            }
+            return ret;
+        }
+    }
+
     if (machine == IMAGE_FILE_MACHINE_AMD64)  /* try the 64-bit loader */
     {
         size_t len = strlen(wineloader);
