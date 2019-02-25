--- apps/netconf/netconf_main.c.orig	2019-02-21 19:04:04 UTC
+++ apps/netconf/netconf_main.c
@@ -312,7 +312,7 @@ static int
 timeout_fn(int s,
 	   void *arg)
 {
-    clicon_err(OE_EVENTS, ETIME, "User request timeout");
+    clicon_err(OE_EVENTS, ETIMEDOUT, "User request timeout");
     return -1; 
 }
 
