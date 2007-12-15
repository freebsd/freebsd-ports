--- lib/rle_hdr.c.orig	Thu Nov 29 21:57:53 2007
+++ lib/rle_hdr.c	Thu Nov 29 21:59:23 2007
@@ -269,6 +269,8 @@
 {
     rle_hdr *ret_hdr;
 
+    if ( rle_dflt_hdr.rle_file == NULL)
+    	rle_dflt_hdr.rle_file = stdout;
     if ( the_hdr == &rle_dflt_hdr )
 	return the_hdr;
 
