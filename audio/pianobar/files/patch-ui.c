--- src/ui.c.orig	2010-10-07 01:54:32.000000000 -0700
+++ src/ui.c	2010-10-08 14:51:28.000000000 -0700
@@ -23,9 +23,6 @@
 
 /* everything that interacts with the user */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
-#define _BSD_SOURCE /* strdup() */
-
 #include <stdio.h>
 #include <stdarg.h>
 #include <unistd.h>
