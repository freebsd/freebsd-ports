--- system.h.orig	2011-06-10 15:27:05.000000000 +0200
+++ system.h	2011-06-10 15:27:09.000000000 +0200
@@ -39,6 +39,8 @@ char * stpncpy(char * dest, const char *
 #define	getenv(_s)	__secure_getenv(_s)
 #endif
 
+#include <sys/wait.h>
+
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #else
