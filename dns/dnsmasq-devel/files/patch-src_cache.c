--- src/cache.c.orig	2025-01-07 23:08:35 UTC
+++ src/cache.c
@@ -479,7 +479,7 @@ static struct crec *cache_scan_free(char *name, union 
 	  if ((crecp->flags & F_FORWARD) && hostname_isequal(cache_get_name(crecp), name))
 	    {
 	      int rrmatch = 0;
-	      if (crecp->flags & flags & F_RR)
+	      if (addr && crecp->flags & flags & F_RR)
 		{
 		  unsigned short rrc = (crecp->flags & F_KEYTAG) ? crecp->addr.rrblock.rrtype : crecp->addr.rrdata.rrtype;
 		  unsigned short rra = (flags & F_KEYTAG) ? addr->rrblock.rrtype : addr->rrdata.rrtype;
