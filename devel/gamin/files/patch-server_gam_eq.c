--- server/gam_eq.c.orig	2012-05-13 19:42:20.257794534 +0400
+++ server/gam_eq.c	2012-05-13 19:44:41.228799909 +0400
@@ -124,7 +124,7 @@ gam_eq_flush (gam_eq_t *eq, GamConnDataP
 {
 	gboolean done_work = FALSE;
 	if (!eq)
-		return;
+		return FALSE;
 
 #ifdef GAM_EQ_VERBOSE
 	GAM_DEBUG(DEBUG_INFO, "gam_eq: Flushing event queue for %s\n", gam_connection_get_pidname (conn));
