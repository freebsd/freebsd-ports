--- camlibs/aox/aox.c.orig	Mon Jan 26 01:24:20 2004
+++ camlibs/aox/aox.c	Mon Jan 26 01:25:54 2004
@@ -39,10 +39,11 @@
 int aox_init (GPPort *port, Model *model, Info *info) 
 {
 	unsigned char c[4];
-	memset(c,0,sizeof(c));
 	unsigned char hi[2];
-	memset (hi,0,2);
 	unsigned char lo[2];
+
+	memset(c,0,sizeof(c));
+	memset (hi,0,2);
 	memset (lo,0,2);
 
 	GP_DEBUG("Running aox_init\n");
@@ -86,11 +87,12 @@
 
 int aox_get_picture_size  (GPPort *port, int lo, int hi, int n, int k) 
 {
+	unsigned char c[4];
+        unsigned int size;
+
 	GP_DEBUG("Running aox_get_picture_size\n");
 
-	unsigned char c[4];
 	memset (c,0,4);
-        unsigned int size;
 
 	if ( ( (lo) && ( n ==k ) && (k ==0)) ) {
 	    	READ(port, 0x04, 0x1, 0x1, c, 2);	
