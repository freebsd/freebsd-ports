--- include/MessageProxy.h.orig	Thu Jan  4 12:28:14 2007
+++ include/MessageProxy.h	Thu Jan  4 12:28:19 2007
@@ -32,7 +32,7 @@
 #include <windows.h>
 #else
 #include <pthread.h>
-#include <asm/errno.h>
+#include <sys/errno.h>
 #endif
 
 #include <vector>
