--- src/ui.c.orig	2011-01-24 04:00:25.000000000 -0800
+++ src/ui.c	2011-04-07 14:29:19.000000000 -0700
@@ -23,9 +23,6 @@
 
 /* everything that interacts with the user */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
-#define _BSD_SOURCE /* strdup() */
-
 #include <stdio.h>
 #include <stdarg.h>
 #include <unistd.h>
