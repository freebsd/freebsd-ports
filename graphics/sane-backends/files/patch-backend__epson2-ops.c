--- backend/epson2-ops.c.orig	2010-04-14 09:52:59.000000000 +0900
+++ backend/epson2-ops.c	2010-05-10 21:59:04.000000000 +0900
@@ -1219,6 +1219,7 @@
 
 	DBG(1, "max req size: %d, line count: %d\n", maxreq, s->lcount);
 
+#if 0
 	/* XXX investigate this */
 	if (s->lcount < 3 && e2_model(s, "GT-X800")) {
 		s->lcount = 21;
@@ -1226,6 +1227,7 @@
 		    "%s: set lcount = %i bigger than sanei_scsi_max_request_size\n",
 		    __func__, s->lcount);
 	}
+#endif
 
 	if (s->lcount >= 255)
 		s->lcount = 255;
