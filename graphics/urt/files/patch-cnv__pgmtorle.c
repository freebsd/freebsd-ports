--- cnv/pgmtorle.c.orig	1992-04-30 22:57:30.000000000 +0900
+++ cnv/pgmtorle.c	2012-10-16 00:55:59.000000000 +0900
@@ -35,6 +35,7 @@
  * System includes.
  */
 #include <stdio.h>
+#include <string.h>
 #include <pgm.h>
 #undef abs			/* Screws up stdlib.h. */
 #define NO_DECLARE_MALLOC
