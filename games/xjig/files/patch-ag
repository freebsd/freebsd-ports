--- reset_image.H.orig	Wed Jul 17 02:59:50 1996
+++ reset_image.H	Fri Aug  6 03:12:24 2004
@@ -16,15 +16,25 @@
 // to access data beyond the allocated image, that might lead to a segmentation
 // violation. Therefore, it might be good to allocated some additional
 // rows of data for the image.
-	offset_bytes=xwidth*offset_rows*sizeof(DATA_TYPE);
-	xdata=new DATA_TYPE[xwidth*(xheight+2*offset_rows)];
+
+	extern int scanline_pad;
+
+	int byte_pad = scanline_pad / 8;
+
+	offset_bytes=xwidth*offset_rows*DATA_BYTES;
+	// xdata=new DATA_TYPE[xwidth*(xheight+2*offset_rows)];
+
+	xdata=(DATA_TYPE*)new char[DATA_BYTES*xwidth*(xheight+2*offset_rows)];
 	{	DATA_TYPE	*xdata_run=xdata;
 		unsigned long blk_pixel=BlackPixel(dpy,scr);
 		for (int i=xwidth*(xheight+2*offset_rows);i>0;i--) {
-			*xdata_run++=(DATA_TYPE)blk_pixel;
+			// *xdata_run++=(DATA_TYPE)blk_pixel;
+			*xdata_run=(DATA_TYPE)blk_pixel; // align fault
+			char *my_xdata_run = (char *)xdata_run;
+			my_xdata_run += DATA_BYTES;
 		}
 	}
-	xdata+=(offset_bytes/sizeof(DATA_TYPE));
+	xdata+=(offset_bytes/DATA_BYTES);
 
 	if (!xdata) {
 		fprintf(stderr,"not enough memory for XImage-data");
@@ -32,9 +42,11 @@
 	}
 
 // create the XImage
+
 	ximage = XCreateImage(dpy, DefaultVisual(dpy,scr),
-				DefaultDepth(dpy,scr), ZPixmap, 0,
-				(char*)xdata, xwidth, xheight, 8*DATA_PAD, xwidth*sizeof(DATA_TYPE));
+			DefaultDepth(dpy,scr), ZPixmap, 0,
+			(char*)xdata, xwidth, xheight, scanline_pad,
+			((xwidth*DATA_BYTES + byte_pad - 1)/byte_pad) * byte_pad);
 
 	if (!ximage) {
 		fprintf(stderr,"\n*** can't allocate ximage.\n" );
@@ -47,9 +59,23 @@
 		register const byte	*org  = Data();
 		register int	j,i;
 
-		for (i=0; i<Height(); i++) {
-			for (j=0; j<Width(); j++) 
-				*copy++ = (DATA_TYPE)gif_cols[*org++];
+		extern int pixmap_depth;
+
+		switch(pixmap_depth) {
+		case 8:		// power of two covered by basic data type
+		case 16:
+		case 32:
+			for (i=0; i<Height(); i++) {
+				for (j=0; j<Width(); j++) 
+					*copy++ = (DATA_TYPE)gif_cols[*org++];
+			}
+			break;
+		case 24:
+			for (i=0; i<Height(); i++) {
+				for (j=0; j<Width(); j++) 
+					XPutPixel(ximage,j,i,gif_cols[*org++]);
+			}
+			break;
 		}
 	}
 	else {
