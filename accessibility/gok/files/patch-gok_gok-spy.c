--- gok/gok-spy.c.orig	Sat May 13 18:49:18 2006
+++ gok/gok-spy.c	Sat May 13 18:49:30 2006
@@ -1406,10 +1406,7 @@ gok_spy_resolve_namesakes (GSList *list)
 	GSList *namesake;
 	gboolean distinguished_source = FALSE;
 
-	name[63] = '\0';
-
 	if (resolve_namesakes_reentry_guard) return;
-
 	else resolve_namesakes_reentry_guard = TRUE;
 
 	gok_log_enter ();
