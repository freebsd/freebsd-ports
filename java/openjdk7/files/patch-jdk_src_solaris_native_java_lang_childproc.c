--- jdk/src/solaris/native/java/lang/childproc.c
+++ jdk/src/solaris/native/java/lang/childproc.c
@@ -33,6 +33,7 @@
 
 #include "childproc.h"
 
+const char * const *parentPathv;
 
 ssize_t
 restartableWrite(int fd, const void *buf, size_t count)
