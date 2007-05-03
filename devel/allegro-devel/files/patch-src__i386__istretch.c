--- ./src/i386/istretch.c.orig	Sat Apr 21 00:54:32 2007
+++ ./src/i386/istretch.c	Thu May  3 16:04:38 2007
@@ -37,7 +37,7 @@
 
 
 #ifdef HAVE_MPROTECT
-   #include <sys/types.h>
+   #include <sys/param.h>
    #include <sys/mman.h>
 #endif     /* ifdef HAVE_MPROTECT */
 
