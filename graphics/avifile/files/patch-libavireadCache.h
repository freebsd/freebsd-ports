--- lib/aviread/Cache.h.orig	Tue Aug 28 22:02:19 2001
+++ lib/aviread/Cache.h	Tue Aug 28 22:02:22 2001
@@ -19,6 +19,7 @@
 #include <string>
 #include <vector>
 #include <list>
+#include <pthread.h>
 
 // Isn't this bug in NetBSD configuration - it should not have HAVE_LSEEK64
 #ifdef __NetBSD__
