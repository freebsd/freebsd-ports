--- apr-1.2.2/misc/unix/rand.c.orig	Wed Nov  2 20:17:10 2005
+++ apr-1.2.2/misc/unix/rand.c	Wed Nov  2 20:17:43 2005
@@ -35,11 +35,10 @@
 #if APR_HAVE_SYS_UN_H
 #include <sys/un.h>
 #endif
-#ifdef HAVE_UUID_UUID_H
-#include <uuid/uuid.h>
-#endif
 #ifdef HAVE_UUID_H
 #include <uuid.h>
+#elif defined(HAVE_UUID_UUID_H)
+#include <uuid/uuid.h>
 #endif
 
 #ifndef SHUT_RDWR
