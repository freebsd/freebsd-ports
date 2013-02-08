--- lib/rle_hdr.c.orig	1992-06-27 05:44:20.000000000 +0900
+++ lib/rle_hdr.c	2012-10-15 22:05:32.000000000 +0900
@@ -26,6 +26,7 @@
  */
 static char rcsid[] = "$Header: /tmp_mnt/n/itn/hendrix/u/spencer/RCS/rle_hdr.c,v 3.0.1.1 1992/04/30 14:08:07 spencer Exp spencer $";
 
+#include <string.h>
 #include "rle.h"
 
 /*****************************************************************
@@ -269,6 +270,8 @@
 {
     rle_hdr *ret_hdr;
 
+    if ( rle_dflt_hdr.rle_file == NULL)
+    	rle_dflt_hdr.rle_file = stdout;
     if ( the_hdr == &rle_dflt_hdr )
 	return the_hdr;
 
