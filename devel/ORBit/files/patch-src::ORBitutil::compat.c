
$FreeBSD$

--- src/ORBitutil/compat.c.orig	Wed Sep  9 07:08:14 1998
+++ src/ORBitutil/compat.c	Mon Oct 29 18:50:04 2001
@@ -1,18 +1,34 @@
+#include <errno.h>
+#include <fcntl.h>
+
 #include "config.h"
 #include "util.h"
 
-#define MAX_IOVS 16
-
 int g_writev(int fd, const struct  iovec *  vector,  size_t count)
 {
-  int retval = 0;
+  int fdflags, retval, wcur;
+  int sum = 0;
 
-  while(count > MAX_IOVS) {
-    retval += writev(fd, vector, MAX_IOVS);
-    vector += MAX_IOVS; count -= MAX_IOVS;
+  fdflags = fcntl(fd, F_GETFL);
+  /* Get rid of the O_NONBLOCK - we don't need it here */
+  fcntl(fd, F_SETFL, fdflags & ~O_NONBLOCK);
+  for (wcur = MAXIOV; wcur == MAXIOV && count != 0; count -= MAXIOV) {
+    if (wcur > count)
+      wcur = count;
+    do {
+      retval = writev(fd, vector, wcur);
+    } while (retval <= 0 && (errno == EAGAIN || errno == EINTR));
+    if (retval < 0) {
+      sum = retval;
+      break;
+    }
+    vector += wcur;
+    sum += retval;
   }
 
-  return writev(fd, vector, count) + retval;
+  /* Restore flags */
+  fcntl(fd, F_SETFD, fdflags);
+  return sum;
 }
 
 #ifndef HAVE_INET_ATON
