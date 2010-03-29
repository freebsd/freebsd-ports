--- sngd.c.orig	2003-11-15 20:25:10.000000000 +0100
+++ sngd.c	2010-03-29 16:10:17.000000000 +0200
@@ -793,17 +793,17 @@
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
