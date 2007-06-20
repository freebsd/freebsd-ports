--- drawcgm/cgm_clip.c.orig	Fri Mar 20 03:28:47 1992
+++ drawcgm/cgm_clip.c	Sat Jun 16 02:08:24 2007
@@ -13,6 +13,8 @@
 #endif
 #if (!VMS)
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #endif
 
 #include "cgm_clip.h"
@@ -85,8 +87,6 @@
 	successful.
 */	
 {
-	char *malloc();
-
 	if (nx>ixbuf_sz)
 		{
 		if (debug) fprintf(stderr,
