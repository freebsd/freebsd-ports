--- diff/diff.c.orig	Sun Feb 22 04:47:45 2004
+++ diff/diff.c	Sun Feb 22 04:56:06 2004
@@ -19,6 +19,7 @@
    Richard Stallman, Len Tower, and Paul Eggert.  */
 
 #define GDIFF_MAIN
+#include "config.h"
 #include "diff.h"
 #include <signal.h>
 #include "getopt1.h"
@@ -29,9 +30,6 @@
 #endif
 
 #ifdef HAVE_UNISTD_H
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE /* Required for snprinf on GNU */
-#endif
 #define __EXTENSIONS__ /* Solaris fix */
 #include <unistd.h>
 #endif
