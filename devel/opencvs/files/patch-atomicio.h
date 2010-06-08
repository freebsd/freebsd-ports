--- atomicio.h.orig	2007-09-17 12:07:21.000000000 +0200
+++ atomicio.h	2010-06-08 20:35:43.000000000 +0200
@@ -28,6 +28,7 @@
 
 #ifndef _ATOMICIO_H
 #define _ATOMICIO_H
+#include <sys/socket.h>
 
 /*
  * Ensure all of data on socket comes through. f==read || f==vwrite
@@ -36,4 +37,10 @@ size_t	atomicio(ssize_t (*)(int, void *,
 
 #define vwrite (ssize_t (*)(int, void *, size_t))write
 
+/*
+ * ensure all of data on socket comes through. f==readv || f==writev
+ */
+size_t	atomiciov(ssize_t (*)(int, const struct iovec *, int),
+    int, const struct iovec *, int);
+
 #endif /* _ATOMICIO_H */
