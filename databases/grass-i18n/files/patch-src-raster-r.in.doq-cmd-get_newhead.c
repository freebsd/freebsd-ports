--- src/raster/r.in.doq/cmd/get_newhead.c.orig	Sun Jul 11 17:17:15 2004
+++ src/raster/r.in.doq/cmd/get_newhead.c	Sun Jul 11 17:17:26 2004
@@ -44,7 +44,7 @@
 /*** Check data ordering ******/
 	if (strstr(buf,"LEFT_RIGHT/TOP_BOTTOM") == NULL) {
 		fprintf(stderr,"Unable to handle this data ordering: %s\n",buf);
-		exit();
+		exit(1);
 		}
 	}
 else if (strstr(buf,"SAMPLES_AND_LINES") != NULL) {
@@ -63,7 +63,7 @@
 /*********** Get # bands now handlws one ***************/
 	if (strstr(buf,"BLACK&WHITE") == NULL) {
 		fprintf(stderr,"There are multiple bands in this image.\n This routine presently handles only one\n");
-		exit();
+		exit(1);
 		}
 	}
 else if (strstr(buf,"HORIZONTAL_DATUM") != NULL) {
