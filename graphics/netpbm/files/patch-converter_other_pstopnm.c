pstopnm.c:268:14: warning: implicit declaration of function 'lstat' is invalid in C99 [-Wimplicit-function-declaration]
    statRc = lstat(origFileName, &statbuf);
             ^

--- converter/other/pstopnm.c.orig	2020-03-27 19:22:48 UTC
+++ converter/other/pstopnm.c
@@ -16,7 +16,6 @@
 
 #define _DEFAULT_SOURCE 1 /* New name for SVID & BSD source defines */
 #define _BSD_SOURCE 1   /* Make sure strdup() is in string.h */
-#define _XOPEN_SOURCE 500
     /* Make sure fdopen() is in stdio.h and strdup() is in string.h */
 
 #include <assert.h>
