--- src/gvcore/pngformattype.cpp.orig	2007-09-15 15:46:13.000000000 +0200
+++ src/gvcore/pngformattype.cpp	2012-05-09 12:32:26.000000000 +0200
@@ -41,6 +41,7 @@
 #include "pngformattype.h"
 
 #include <png.h>
+#include <pngpriv.h>
 
 namespace Gwenview {
 
@@ -245,7 +246,7 @@
 		image.setColor( i, qRgba(c,c,c,0xff) );
 	    }
 	    if ( png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS) ) {
-		const int g = info_ptr->trans_values.gray;
+		const int g = info_ptr->trans_color.gray;
 		if (g < ncols) {
 		    image.setAlphaBuffer(TRUE);
 		    image.setColor(g, image.color(g) & RGB_MASK);
@@ -273,7 +274,7 @@
 		    info_ptr->palette[i].red,
 		    info_ptr->palette[i].green,
 		    info_ptr->palette[i].blue,
-		    info_ptr->trans[i]
+		    info_ptr->trans_alpha[i]
 		    )
 		);
 		i++;
@@ -381,7 +382,7 @@
 	    return -1;
 	}
 
-	if (setjmp((png_ptr)->jmpbuf)) {
+	if (setjmp(png_jmpbuf((png_ptr)))) {
 	    png_destroy_read_struct(&png_ptr, &info_ptr, 0);
 	    image = 0;
 	    return -1;
@@ -409,7 +410,7 @@
 
     if ( !png_ptr ) return 0;
 
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
 	image = 0;
 	state = MovieStart;
