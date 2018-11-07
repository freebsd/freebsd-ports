--- apps/netconf/netconf_main.c.orig	2018-11-07 19:13:50 UTC
+++ apps/netconf/netconf_main.c
@@ -294,7 +294,7 @@ static int
 timeout_fn(int s,
 	   void *arg)
 {
-    clicon_err(OE_EVENTS, ETIME, "User request timeout");
+    clicon_err(OE_EVENTS, ETIMEDOUT, "User request timeout");
     return -1; 
 }
 
