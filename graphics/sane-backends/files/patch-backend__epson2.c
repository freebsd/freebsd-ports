--- backend/epson2.c.orig	2009-04-30 22:15:19.000000000 +0900
+++ backend/epson2.c	2009-05-05 02:16:46.000000000 +0900
@@ -3446,12 +3446,14 @@
 	 */
 	DBG(1, "max req size: %d\n", sanei_scsi_max_request_size);
 
+#if 0
 	if (s->lcount < 3 && e2_model(s, "GT-X800")) {
 		s->lcount = 21;
 		DBG(17,
 		    "%s: set lcount = %i bigger than sanei_scsi_max_request_size\n",
 		    __func__, s->lcount);
 	}
+#endif
 
 	if (s->lcount >= 255) {
 		s->lcount = 255;
