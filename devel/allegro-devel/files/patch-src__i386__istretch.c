--- src/i386/istretch.c.orig	Mon Jul 24 09:10:50 2006
+++ src/i386/istretch.c	Wed Aug  9 19:03:27 2006
@@ -33,9 +33,8 @@
 
 
 #ifdef HAVE_MPROTECT
-   #include <sys/types.h>
+   #include <sys/param.h>
    #include <sys/mman.h>
-   #include <sys/user.h>
 #endif     /* ifdef HAVE_MPROTECT */
 
 
