
$FreeBSD$

--- ../src/solaris/hpi/green_threads/src/iomgr.c.orig	Wed Sep 12 12:39:31 2001
+++ ../src/solaris/hpi/green_threads/src/iomgr.c	Wed Sep 12 12:39:43 2001
@@ -716,6 +716,22 @@
     WRAPFUNC(read);
     WRAPFUNC(write);
     WRAPFUNC(fcntl);
+#if __FreeBSD__ >= 5
+    WRAPFUNC(writev);
+    WRAPFUNC(readv);
+    WRAPFUNC(poll);
+    WRAPFUNC(sendto);
+    WRAPFUNC(dup);
+    WRAPFUNC(accept);
+    WRAPFUNC(recvfrom);
+    WRAPFUNC(socket);
+    WRAPFUNC(connect);
+    WRAPFUNC(select);
+    WRAPFUNC(pipe);
+    WRAPFUNC(creat);
+    WRAPFUNC(recv);
+    WRAPFUNC(send);
+#endif
     __dummy();
 }
 #else
