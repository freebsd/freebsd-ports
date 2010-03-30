--- src/gvcore/pngformattype.cpp.orig	2007-09-15 15:46:13.000000000 +0200
+++ src/gvcore/pngformattype.cpp	2010-03-30 10:12:59.000000000 +0200
@@ -245,7 +245,7 @@
 		image.setColor( i, qRgba(c,c,c,0xff) );
 	    }
 	    if ( png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS) ) {
-		const int g = info_ptr->trans_values.gray;
+		const int g = info_ptr->trans_color.gray;
 		if (g < ncols) {
 		    image.setAlphaBuffer(TRUE);
 		    image.setColor(g, image.color(g) & RGB_MASK);
@@ -273,7 +273,7 @@
 		    info_ptr->palette[i].red,
 		    info_ptr->palette[i].green,
 		    info_ptr->palette[i].blue,
-		    info_ptr->trans[i]
+		    info_ptr->trans_alpha[i]
 		    )
 		);
 		i++;
