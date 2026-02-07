--- vfe/unix/syspovconfig.h.orig	2018-05-27 09:54:06 UTC
+++ vfe/unix/syspovconfig.h
@@ -162,7 +162,8 @@ const int NULL=0;
     #include <sys/param.h>
     #if defined(BSD)
         // BSD-style Unix detected.
-        #error BSD-style Unix detected, but not explicitly supported yet; proceed at your own risk.
+        #include <sys/wait.h> // for WEXITSTATUS
+        #define lseek64(handle,offset,whence) lseek(handle,offset,whence)
     #else
         // Not officially supported yet; comment-out the following line to try with default POSIX settings.
         #error Unix detected, but flavor not identified; proceed at your own risk.
