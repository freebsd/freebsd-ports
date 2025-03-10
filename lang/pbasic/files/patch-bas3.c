--- bas3.c.orig
+++ bas3.c
@@ -2,6 +2,7 @@
  * BASIC by Phil Cockcroft
  */
 #include        "bas.h"
+#include        <errno.h>
 
 /*
  *      This file contains the numeric evaluation routines and some
@@ -1513,7 +1514,6 @@
  */
 #define	MAX_SYS_ARGS	6
 
-extern	int	errno;
 #ifdef	__STDC__
 extern	int	syscall(int, ...);
 #else
