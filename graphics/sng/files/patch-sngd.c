--- sngd.c.orig	2014-06-05 17:02:15.635246968 +0100
+++ sngd.c	2014-06-05 17:02:31.866045210 +0100
@@ -738,8 +738,8 @@
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
