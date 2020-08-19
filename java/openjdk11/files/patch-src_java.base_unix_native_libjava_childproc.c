--- src/java.base/unix/native/libjava/childproc.c.orig	2020-07-15 18:00:08 UTC
+++ src/java.base/unix/native/libjava/childproc.c
@@ -33,6 +33,7 @@
 
 #include "childproc.h"
 
+const char * const *parentPathv;
 
 ssize_t
 restartableWrite(int fd, const void *buf, size_t count)
