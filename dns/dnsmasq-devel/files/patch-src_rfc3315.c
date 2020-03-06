--- src/rfc3315.c.orig	2020-03-05 22:13:45 UTC
+++ src/rfc3315.c
@@ -1708,7 +1708,7 @@ static int config_valid(struct dhcp_config *config, st
     return 0;
 
   for (addr_list = config->addr6; addr_list; addr_list = addr_list->next)
-    if (!(addr_list->flags && ADDRLIST_DECLINED) ||
+    if (!(addr_list->flags & ADDRLIST_DECLINED) ||
 	difftime(now, addr_list->decline_time) >= (float)DECLINE_BACKOFF)
       {
 	addrpart = addr6part(&addr_list->addr.addr6);
