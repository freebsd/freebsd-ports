--- diff/diff3.c.orig	Sun Feb 22 04:57:07 2004
+++ diff/diff3.c	Sun Feb 22 04:57:14 2004
@@ -26,9 +26,6 @@
 #include "diffrun.h"
 
 #ifdef HAVE_UNISTD_H
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE /* Required for snprinf on GNU */
-#endif
 #define __EXTENSIONS__ /* Solaris fix */
 #include <unistd.h>
 #endif
