--- rotate.H.orig	Wed Jul 24 15:15:11 1996
+++ rotate.H	Tue Apr  7 15:34:34 1998
@@ -6,7 +6,6 @@
 // while compiling that function:
 //
 // #define DATA_TYPE unsigned char
-// #define DATA_PAD  1
 
 #define	IMAX	1000
 
@@ -21,7 +20,9 @@
 	}
 	else		wcenter=center;
 
-	ximage = img_buf->Init(width,height,DATA_PAD);
+	extern int scanline_pad;
+
+	ximage = img_buf->Init(width,height,scanline_pad/8);
 
 	if (!itm) {
 		if (page) {
@@ -40,7 +41,10 @@
 		edge=wcenter+(*itm)*Vec2(-offx,-offy);
 	}
 
-#if (0)
+extern int pixmap_depth;
+
+switch(pixmap_depth) {
+case 24:
 
 //
 // the traditional routine to copy each pixel from one image to the other
@@ -52,6 +56,15 @@
 
 	for (int y=0;y<height;y++) {
 		Vec2	pt=edge+y*diry;
+		for (int x=0;x<width;x++) {
+			XPutPixel(ximage,x,y,pm->GetPixel( XPix(pt.X()), YPix(pt.Y()) ));
+			pt+=dirx;
+		}
+	}
+
+#if 0
+	for (int y=0;y<height;y++) {
+		Vec2	pt=edge+y*diry;
 		/* x,y, dx,dy bestimmen ... */
 		register DATA_TYPE	*dest = (DATA_TYPE*)(ximage->data + y * ximage->bytes_per_line);
 		for (int x=0;x<width;x++) {
@@ -59,8 +72,12 @@
 			pt+=dirx;
 		}
 	}
+#endif
 
-#else
+break;
+case 8:
+case 16:
+case 32:
 
 //
 // optimized mapping
@@ -209,7 +226,7 @@
 			}
 		}
 	}
-#endif
+}
 
 	img_buf->PutImage(dpy,tilemap,DefaultGC(dpy,scr),0,0,0,0,width,height);
 
