--- src/svsem.c.orig	Wed May 26 16:32:24 2004
+++ src/svsem.c	Mon Feb 21 00:31:21 2005
@@ -42,7 +42,7 @@
 #include "mba/msgno.h"
 #include "defines.h"
 
-#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
+#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED) || defined(__FreeBSD__)
 /* union semun is defined by including <sys/sem.h> */
 #include <sys/sem.h>
 #else
@@ -108,7 +108,7 @@
 					sleep(1);
 				}
 	
-				errno = ETIME;
+				errno = ETIMEDOUT;
 				PMNF(errno, ": %s", name);
 				return -1;
 			} else if (errno != ENOENT) {
@@ -296,7 +296,7 @@
 		int fd, cre;
 
 		va_start(ap, oflag);
-		mode = va_arg(ap, mode_t);
+		mode = va_arg(ap, int);
 		val = va_arg(ap, unsigned int);
 		va_end(ap);
 
