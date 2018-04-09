--- bin/named/server.c.orig	2018-04-06 06:10:50 UTC
+++ bin/named/server.c
@@ -3552,7 +3552,7 @@ configure_dnstap(const cfg_obj_t **maps,
 			fstrm_iothr_options_set_reopen_interval(fopt, i);
 		}
 
-		CHECKM(dns_dt_create2(named_g_mctx, dmode, dpath,
+		CHECKM(dns_dt_create(named_g_mctx, dmode, dpath,
 				      &fopt, named_g_server->task,
 				      &named_g_server->dtenv),
 		       "unable to create dnstap environment");
