--- server/gam_poll_basic.c.orig	Mon Feb  6 22:55:40 2006
+++ server/gam_poll_basic.c	Mon Feb  6 22:58:47 2006
@@ -335,7 +335,11 @@
 	} else {
 #ifdef VERBOSE_POLL
 		GAM_DEBUG(DEBUG_INFO, "Poll: poll_file %s unchanged\n", path);
+#ifdef ST_MTIM_NSEC
 		GAM_DEBUG(DEBUG_INFO, "%d %d : %d %d\n", node->sbuf.st_mtim.tv_sec, node->sbuf.st_mtim.tv_nsec, sbuf.st_mtim.tv_sec, sbuf.st_mtim.tv_nsec);
+#else
+		GAM_DEBUG(DEBUG_INFO, "%d : %d\n", node->sbuf.st_mtime, sbuf.st_mtime);
+#endif
 #endif
 	}
 
