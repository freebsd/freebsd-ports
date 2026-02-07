--- server/gam_poll_basic.c.orig	2007-08-10 15:12:29.000000000 -0400
+++ server/gam_poll_basic.c	2007-08-10 15:16:07.000000000 -0400
@@ -345,7 +345,7 @@ gam_poll_basic_poll_file(GamNode * node)
 #ifdef ST_MTIM_NSEC
 		GAM_DEBUG(DEBUG_INFO, "%d %d : %d %d\n", node->sbuf.st_mtim.tv_sec, node->sbuf.st_mtim.tv_nsec, sbuf.st_mtim.tv_sec, sbuf.st_mtim.tv_nsec);
 #else
-		GAM_DEBUG(DEBUG_INFO, "%d : %d\n", node->sbuf.st_mtime, sbuf.st_mtim.tv_nsec);
+		GAM_DEBUG(DEBUG_INFO, "%d : %d\n", node->sbuf.st_mtime, sbuf.st_mtime);
 #endif /* ST_MTIM_NSEC */
 #endif /* VERBOSE_POLL */
 	}
