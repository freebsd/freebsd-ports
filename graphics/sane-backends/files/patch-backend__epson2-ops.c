--- backend/epson2-ops.c.orig	2015-09-19 15:18:44 UTC
+++ backend/epson2-ops.c
@@ -1286,6 +1286,7 @@ e2_setup_block_mode(Epson_Scanner * s)
 
 	DBG(1, "max req size: %d, line count: %d\n", maxreq, s->lcount);
 
+#if 0
 	/* XXX investigate this */
 	if (s->lcount < 3 && (e2_model(s, "GT-X800") || e2_model(s, "GT-X900") || e2_model(s, "GT-X980"))) {
 		s->lcount = 21;
@@ -1293,6 +1294,7 @@ e2_setup_block_mode(Epson_Scanner * s)
 		    "%s: set lcount = %i bigger than sanei_scsi_max_request_size\n",
 		    __func__, s->lcount);
 	}
+#endif
 
 	if (s->lcount >= 255)
 		s->lcount = 255;
