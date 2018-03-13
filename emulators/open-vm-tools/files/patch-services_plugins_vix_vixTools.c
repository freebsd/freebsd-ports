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
@@ -7373,6 +7374,9 @@ VixToolsRunScript(VixCommandRequestHeader *requestMsg,
           */
          break;
       }
+      if (var == INT_MAX) {
+         break;
+      }
    }
    if (fd < 0) {
       /*
@@ -10131,7 +10135,7 @@ abort:
    struct passwd pwd;
    struct passwd *ppwd = &pwd;
    char *buffer = NULL; // a pool of memory for Posix_Getpwnam_r() to use.
-   size_t bufferSize;
+   long bufferSize;
 
    /*
     * For POSIX systems, look up the uid of 'username', and compare
@@ -10144,9 +10148,15 @@ abort:
     * Multiply by 4 to compensate for the conversion to UTF-8 by
     * the Posix_Getpwnam_r() wrapper.
     */
-   bufferSize = (size_t) sysconf(_SC_GETPW_R_SIZE_MAX) * 4;
+   errno = 0;
+   bufferSize = sysconf(_SC_GETPW_R_SIZE_MAX);
+   if ((errno != 0) || (bufferSize <= 0)) {
+      bufferSize = 16 * 1024;  // Unlimited; pick something reasonable
+   }
 
-   buffer = Util_SafeMalloc(bufferSize);
+   bufferSize *= 4;
+
+   buffer = Util_SafeMalloc((size_t)bufferSize);
 
    if (Posix_Getpwnam_r(username, &pwd, buffer, bufferSize, &ppwd) != 0 ||
        NULL == ppwd) {
