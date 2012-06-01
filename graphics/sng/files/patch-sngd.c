--- sngd.c.orig	2012-05-04 08:20:04.000000000 +0200
+++ sngd.c	2012-05-04 08:42:54.000000000 +0200
@@ -10,6 +10,7 @@
 #define PNG_INTERNAL
 #include "config.h"	/* for RGBTXT */
 #include "png.h"
+#include "pngpriv.h"
 #include "sng.h"
 
 png_structp png_ptr;
@@ -726,8 +727,8 @@
 	}
 #ifdef PNG_FLOATING_POINT_SUPPORTED
 #ifndef MNG_INTERFACE
-	fprintf(fpout, "    width:  %g\n", info_ptr->scal_pixel_width);
-	fprintf(fpout, "    height: %g\n", info_ptr->scal_pixel_height);
+	fprintf(fpout, "    width:  %s\n", info_ptr->scal_s_width);
+	fprintf(fpout, "    height: %s\n", info_ptr->scal_s_height);
 #else
 	fprintf(fpout, "    width:  %g\n", info_ptr->scal.pixel_width);
 	fprintf(fpout, "    height: %g\n", info_ptr->scal.pixel_height);
@@ -794,17 +795,17 @@
 	fprintf(fpout, "tRNS {\n");
 	switch (info_ptr->color_type) {
 	case PNG_COLOR_TYPE_GRAY:
-	    fprintf(fpout, "    gray: %u;\n", info_ptr->trans_values.gray);
+	    fprintf(fpout, "    gray: %u;\n", info_ptr->trans_color.gray);
 	    break;
 	case PNG_COLOR_TYPE_RGB:
 	    fprintf(fpout, "    red: %u; green: %u; blue: %u;\n",
-		    info_ptr->trans_values.red,
-		    info_ptr->trans_values.green,
-		    info_ptr->trans_values.blue);
+		    info_ptr->trans_color.red,
+		    info_ptr->trans_color.green,
+		    info_ptr->trans_color.blue);
 	    break;
 	case PNG_COLOR_TYPE_PALETTE:
 	    for (i = 0; i < info_ptr->num_trans; i++)
-		fprintf(fpout, " %u", info_ptr->trans[i]);
+		fprintf(fpout, " %u", info_ptr->trans_alpha[i]);
 	    break;
 	case PNG_COLOR_TYPE_GRAY_ALPHA:
 	case PNG_COLOR_TYPE_RGB_ALPHA:
