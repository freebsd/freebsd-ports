--- diff/diff.c.orig	Sun Jan  4 06:31:52 2004
+++ diff/diff.c	Sun Feb 22 05:33:08 2004
@@ -29,9 +29,6 @@
 #endif
 
 #ifdef HAVE_UNISTD_H
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE /* Required for snprinf on GNU */
-#endif
 #define __EXTENSIONS__ /* Solaris fix */
 #include <unistd.h>
 #endif
