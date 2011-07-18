--- src/ui.c.orig	2011-07-09 01:40:54.000000000 -0700
+++ src/ui.c	2011-07-14 12:02:04.000000000 -0700
@@ -23,7 +23,6 @@
 
 /* everything that interacts with the user */
 
-#define _POSIX_C_SOURCE 1 /* fileno() */
 #define _BSD_SOURCE /* strdup() */
 
 #include <stdio.h>
