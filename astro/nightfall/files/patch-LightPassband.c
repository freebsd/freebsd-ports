--- LightPassband.c.orig	2021-04-26 15:54:23 UTC
+++ LightPassband.c
@@ -1455,7 +1455,7 @@ void    nf_pb_readInternal()
 	      snprintf(msg, sizeof(msg),
 		       _("no flux data in external passband %d (%s)"),
 		       pos,
-		       (pb_bands[pos].name) ? pb_bands[pos].name : "NULL");
+		       (pb_bands[pos].name[0]) ? pb_bands[pos].name : "NULL");
 	      WARNING(msg);
 	    }
 	  else
