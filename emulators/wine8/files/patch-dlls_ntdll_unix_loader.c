--- dlls/ntdll/unix/loader.c.orig	2023-07-19 15:29:22 UTC
+++ dlls/ntdll/unix/loader.c
@@ -694,6 +694,21 @@ static NTSTATUS loader_exec( char **argv, WORD machine
 {
     if (machine != current_machine)
     {
+        char* wineserver_path = getenv("WINESERVER");
+        if (wineserver_path != NULL && wineserver_path[0] == '/') {
+            char* s = remove_tail(wineserver_path, "server");
+            if (s != NULL) {
+                if (machine == IMAGE_FILE_MACHINE_AMD64) {
+                    argv[1] = malloc(strlen(s) + 3);
+                    strcpy(argv[1], s);
+                    strcat(argv[1], "64");
+                } else {
+                    argv[1] = s;
+                }
+                preloader_exec(argv);
+            }
+        }
+
         if (machine == IMAGE_FILE_MACHINE_AMD64)  /* try the 64-bit loader */
         {
             size_t len = strlen(wineloader);
