
$FreeBSD$

--- src/ORBitutil/compat.c.orig	Wed Sep  9 07:08:14 1998
+++ src/ORBitutil/compat.c	Sat Oct 27 15:49:13 2001
@@ -1,18 +1,28 @@
+#include <errno.h>
+
 #include "config.h"
 #include "util.h"
 
-#define MAX_IOVS 16
-
 int g_writev(int fd, const struct  iovec *  vector,  size_t count)
 {
-  int retval = 0;
+  int retval, wcur;
+  int sum = 0;
 
-  while(count > MAX_IOVS) {
-    retval += writev(fd, vector, MAX_IOVS);
-    vector += MAX_IOVS; count -= MAX_IOVS;
+  for (wcur = MAXIOV; wcur == MAXIOV && count != 0; count -= MAXIOV) {
+    if (wcur > count)
+      wcur = count;
+    do {
+      retval = writev(fd, vector, wcur);
+    } while (retval < 0 && errno == EAGAIN);
+    if (retval < 0) {
+      sum = retval;
+      break;
+    }
+    vector = &(vector[wcur]);
+    sum += retval;
   }
 
-  return writev(fd, vector, count) + retval;
+  return sum;
 }
 
 #ifndef HAVE_INET_ATON
