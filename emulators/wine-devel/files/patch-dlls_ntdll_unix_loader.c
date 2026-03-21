--- dlls/ntdll/unix/loader.c.orig	2026-03-06 20:41:46 UTC
+++ dlls/ntdll/unix/loader.c
@@ -418,6 +418,24 @@ char *get_alternate_wineloader( WORD machine )
     BOOL force_wow64 = (arch = getenv( "WINEARCH" )) && !strcmp( arch, "wow64" );
     char *ret = NULL;
 
+    if (machine == current_machine) return NULL;
+
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
+
     if (is_win64)
     {
         if (force_wow64) return NULL;
