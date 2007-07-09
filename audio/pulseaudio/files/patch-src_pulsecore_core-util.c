--- src/pulsecore/core-util.c.orig	Sun Jul  8 18:35:21 2007
+++ src/pulsecore/core-util.c	Sun Jul  8 18:39:04 2007
@@ -40,6 +40,7 @@
 #include <time.h>
 #include <ctype.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 
@@ -544,6 +545,7 @@ fail:
         cap_free(caps);
     }
 #endif
+    ;
 }
 
 /* Reset the priority to normal, inverting the changes made by pa_raise_priority() */
@@ -838,22 +840,22 @@ int pa_check_in_group(gid_t g) {
   (advisory on UNIX, mandatory on Windows) */
 int pa_lock_fd(int fd, int b) {
 #ifdef F_SETLKW
-    struct flock flock;
+    struct flock pa_flock;
 
     /* Try a R/W lock first */
 
-    flock.l_type = b ? F_WRLCK : F_UNLCK;
-    flock.l_whence = SEEK_SET;
-    flock.l_start = 0;
-    flock.l_len = 0;
+    pa_flock.l_type = b ? F_WRLCK : F_UNLCK;
+    pa_flock.l_whence = SEEK_SET;
+    pa_flock.l_start = 0;
+    pa_flock.l_len = 0;
 
-    if (fcntl(fd, F_SETLKW, &flock) >= 0)
+    if (fcntl(fd, F_SETLKW, &pa_flock) >= 0)
         return 0;
 
     /* Perhaps the file descriptor qas opened for read only, than try again with a read lock. */
     if (b && errno == EBADF) {
-        flock.l_type = F_RDLCK;
-        if (fcntl(fd, F_SETLKW, &flock) >= 0)
+        pa_flock.l_type = F_RDLCK;
+        if (fcntl(fd, F_SETLKW, &pa_flock) >= 0)
             return 0;
     }
 
