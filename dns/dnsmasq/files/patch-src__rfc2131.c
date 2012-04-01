--- ./src/rfc2131.c.orig	2012-03-04 21:04:22.000000000 +0100
+++ ./src/rfc2131.c	2012-04-01 13:14:33.000000000 +0200
@@ -2095,7 +2095,8 @@
   struct dhcp_netid_list *id_list;
 
   /* filter options based on tags, those we want get DHOPT_TAGOK bit set */
-  context->netid.next = NULL;
+  if (context)
+    context->netid.next = NULL;
   tagif = option_filter(netid, context && context->netid.net ? &context->netid : NULL, config_opts);
 	
   /* logging */
