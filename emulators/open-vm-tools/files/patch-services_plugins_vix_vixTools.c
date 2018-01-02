--- services/plugins/vix/vixTools.c.orig	2017-12-15 21:11:49 UTC
+++ services/plugins/vix/vixTools.c
@@ -52,6 +52,7 @@
 #include <stdarg.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <limits.h>
 
 #ifdef _WIN32
 #include <WTypes.h>
@@ -7330,7 +7331,7 @@ VixToolsRunScript(VixCommandRequestHeader *requestMsg,
          goto abort;
       }
    }
-   for (var = 0; var <= 0xFFFFFFFF; var++) {
+   for (var = 0; ; var++) {
       free(tempScriptFilePath);
       tempScriptFilePath = Str_SafeAsprintf(NULL,
                                             "%s"DIRSEPS"%s%d%s",
@@ -7372,6 +7373,9 @@ VixToolsRunScript(VixCommandRequestHeader *requestMsg,
           * deletes it), we should not try 4+ billion times.
           */
          break;
+      }
+      if (var == INT_MAX) {
+          break;
       }
    }
    if (fd < 0) {
