--- rtelnet.c.orig	2019-06-17 13:22:22 UTC
+++ rtelnet.c
@@ -900,7 +900,7 @@ cf_rtelnet_port(void *cs, char **argv, i
 
 	if (isdigit((unsigned char)argv[1][0])) {
 		ro->ro_port = atoi(argv[1]);
-		if (ro->ro_port < 0 || ro->ro_port > IPPORT_ANONMAX)
+		if (ro->ro_port < 0 || ro->ro_port > IPPORT_MAX)
 			return (config_err(cs, "Invalid port number '%s'",
 			    argv[1]));
 	} else
