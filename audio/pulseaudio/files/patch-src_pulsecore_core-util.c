--- src/pulsecore/core-util.c.orig	2008-09-08 19:33:30.000000000 -0400
+++ src/pulsecore/core-util.c	2008-09-28 19:50:24.000000000 -0400
@@ -37,6 +37,7 @@
 #include <time.h>
 #include <ctype.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <dirent.h>
@@ -567,6 +568,7 @@ int pa_make_realtime(int rtprio) {
     errno = ENOTSUP;
     return -1;
 #endif
+    ;
 }
 
 /* This is merely used for giving the user a hint. This is not correct
@@ -1131,22 +1133,22 @@ int pa_check_in_group(gid_t g) {
   (advisory on UNIX, mandatory on Windows) */
 int pa_lock_fd(int fd, int b) {
 #ifdef F_SETLKW
-    struct flock flock;
+    struct flock pa_flock;
 
     /* Try a R/W lock first */
 
-    flock.l_type = (short) (b ? F_WRLCK : F_UNLCK);
-    flock.l_whence = SEEK_SET;
-    flock.l_start = 0;
-    flock.l_len = 0;
+    pa_flock.l_type = (short) (b ? F_WRLCK : F_UNLCK);
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
 
@@ -2334,7 +2336,11 @@ int pa_reset_sigs(int except, ...) {
 int pa_reset_sigsv(const int except[]) {
     int sig;
 
+#ifdef _NSIG
     for (sig = 1; sig < _NSIG; sig++) {
+#else
+    for (sig = 1; sig < NSIG; sig++) {
+#endif
         pa_bool_t reset = TRUE;
 
         switch (sig) {
