$FreeBSD$

--- pvoc.c.orig	Sun Jul 14 16:03:01 2002
+++ pvoc.c	Sun Jul 14 16:02:55 2002
@@ -8,7 +8,7 @@
 #include "sysdep.h"
 
 #include <stdio.h>
-#if defined(mac_classic) || defined(SYMANTEC)
+#if defined(mac_classic) || defined(SYMANTEC) || defined(__FreeBSD__)
 #  include <stdlib.h>           /* for malloc() */
 #  define READMODE "rb"
 #  define WRITEMODE "wb+"
