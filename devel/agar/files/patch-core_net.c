Index: core/net.c
===================================================================
--- core/net.c.orig	2015-08-24 07:59:45 UTC
+++ core/net.c
@@ -496,7 +496,7 @@ AG_InitNetworkSubsystem(const AG_NetOps *ops)
 void
 AG_DestroyNetworkSubsystem(void)
 {
-	if (agNetOps != NULL) {
+	if (agNetOps != NULL && agNetOps->destroy != NULL) {
 		agNetOps->destroy();
 	}
 	agNetOps = NULL;
