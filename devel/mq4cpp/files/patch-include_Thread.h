--- include/Thread.h.orig	Mon Dec 18 02:57:52 2006
+++ include/Thread.h	Thu Jan  4 12:26:18 2007
@@ -27,7 +27,7 @@
 #include <windows.h>
 #else
 #include <pthread.h>
-#include <asm/errno.h>
+#include <sys/errno.h>
 #endif
 
 class ThreadException : public Exception
