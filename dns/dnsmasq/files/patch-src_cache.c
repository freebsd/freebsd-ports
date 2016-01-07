--- src/cache.c.orig	2015-07-30 19:59:07 UTC
+++ src/cache.c
@@ -481,7 +481,7 @@ struct crec *cache_insert(char *name, st
 	 existing record is for an A or AAAA and
 	 the record we're trying to insert is the same, 
 	 just drop the insert, but don't error the whole process. */
-      if ((flags & (F_IPV4 | F_IPV6)) && (flags & F_FORWARD))
+      if ((flags & (F_IPV4 | F_IPV6)) && (flags & F_FORWARD) && addr)
 	{
 	  if ((flags & F_IPV4) && (new->flags & F_IPV4) &&
 	      new->addr.addr.addr.addr4.s_addr == addr->addr.addr4.s_addr)
