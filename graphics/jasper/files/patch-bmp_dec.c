--- src/libjasper/bmp/bmp_dec.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/bmp/bmp_dec.c	2013-04-17 22:32:23.000000000 +0200
@@ -283,7 +283,7 @@
 	}
 
 	if (info->numcolors > 0) {
-		if (!(info->palents = jas_malloc(info->numcolors *
+		if (!(info->palents = jas_malloc2(info->numcolors,
 		  sizeof(bmp_palent_t)))) {
 			bmp_info_destroy(info);
 			return 0;
