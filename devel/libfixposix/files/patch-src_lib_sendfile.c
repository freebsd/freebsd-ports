Changes `lfp_sendfile' so it returns the number of bytes sent,
mimicking Linux sendfile(2).

Submited to upstream by Vasily Postnicov (shamaz.mazum@gmail.com),
see https://github.com/sionescu/libfixposix/pull/18.

--- src/lib/sendfile.c.orig	2022-01-18 20:14:50 UTC
+++ src/lib/sendfile.c
@@ -38,6 +38,7 @@ int sendfile(int, int, off_t, off_t *, void *, int);
 #endif
 
 #include <stdlib.h>
+#include <errno.h>
 
 DSO_PUBLIC ssize_t
 lfp_sendfile(int out_fd, int in_fd, off_t offset, size_t nbytes)
@@ -46,18 +47,25 @@ lfp_sendfile(int out_fd, int in_fd, off_t offset, size
 # if defined(__linux__)
     off_t off = offset;
     return (ssize_t) sendfile(out_fd, in_fd, &off, nbytes);
-# elif defined(__FreeBSD__)
-    return (ssize_t) sendfile(in_fd, out_fd, offset, nbytes, NULL, NULL, SF_MNOWAIT);
-# elif defined(__DragonFly__)
-    return (ssize_t) sendfile(in_fd, out_fd, offset, nbytes, NULL, NULL, 0);
+# elif defined(__FreeBSD__) || defined(__DragonFly__)
+    off_t sbytes = 0;
+    int res = sendfile(in_fd, out_fd, offset, nbytes, NULL, &sbytes, 0);
+    if (res == 0 || (res < 0 && errno == EAGAIN && sbytes > 0)) {
+        return sbytes;
+    }
+    return -1;
 # elif defined(__APPLE__)
     off_t len = nbytes;
-    return (ssize_t) sendfile(in_fd, out_fd, offset, &len, NULL, 0);
+    int res = sendfile(in_fd, out_fd, offset, &len, NULL, 0);
+    if (res == 0 || (res < 0 && errno == EAGAIN && len > 0)) {
+        return len;
+    }
+    return -1;
 # else
 #  error "It appears that this OS has sendfile(), but LFP doesn't use it at the moment"
 #  error "Please send an email to iolib-devel@common-lisp.net"
 # endif
 #else
-    return ENOSYS;
+    SYSERR(ENOSYS);
 #endif
 }
