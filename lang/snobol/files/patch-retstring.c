--- lib/snolib/retstring.c.orig	Sun Jul  6 20:48:22 1997
+++ lib/snolib/retstring.c	Tue Nov 28 00:12:09 2006
@@ -1,5 +1,7 @@
 /* $Id: retstring.c,v 1.3 1997/07/07 03:48:18 phil Exp $ */
 
+#include <stdlib.h>
+
 #include "h.h"
 #include "equ.h"			/* BCDFLD, etc */
 #include "snotypes.h"			/* DESCR, etc */
@@ -14,7 +16,6 @@
     static struct spec sp[1];
     static char *retbuf;
     static int retbuflen;
-    extern char *malloc();
 
     if (len > retbuflen) {
 	if (retbuf)
