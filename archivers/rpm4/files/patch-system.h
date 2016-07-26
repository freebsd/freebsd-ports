--- system.h.orig	2014-06-30 08:47:14 UTC
+++ system.h
@@ -41,6 +41,13 @@ char * stpncpy(char * dest, const char *
 #define	getenv(_s)	__secure_getenv(_s)
 #endif
 
+/* Add includes for missing libc prototypes */
+#include <ctype.h>
+#include <string.h>
+#include <libgen.h>
+#include <sys/wait.h>
+#include <netinet/in.h>
+
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #else
