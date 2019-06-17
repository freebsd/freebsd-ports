--- listener.c.orig	2009-11-16 14:30:13 UTC
+++ listener.c
@@ -189,11 +189,6 @@ listener_destroy(struct client_ctx *cc)
 	    NULL)
 		context_del_client(cc->cc_ctx, ccc);
 
-	if (lc->lc_args.la_address)
-		(void) free(lc->lc_args.la_address);
-	if (lc->lc_args.la_port)
-		(void) free(lc->lc_args.la_port);
-
 	(void) free(lc);
 }
 
