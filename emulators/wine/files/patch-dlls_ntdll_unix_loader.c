--- dlls/ntdll/unix/loader.c.orig	2024-04-05 17:03:05 UTC
+++ dlls/ntdll/unix/loader.c
@@ -480,6 +480,21 @@ char *get_alternate_wineloader( WORD machine )
 
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
     /* try the 64-bit loader */
     if (current_machine == IMAGE_FILE_MACHINE_I386 && machine == IMAGE_FILE_MACHINE_AMD64)
     {
