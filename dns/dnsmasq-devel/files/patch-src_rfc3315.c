--- src/rfc3315.c.orig	2020-03-02 18:11:22 UTC
+++ src/rfc3315.c
@@ -1190,7 +1190,7 @@ static int dhcp6_no_relay(struct state *state, int msg
 		/* align */
 		memcpy(&addr, opt6_ptr(ia_option, 0), IN6ADDRSZ);
 
-		if (have_config(config, CONFIG_ADDR6) && IN6_ARE_ADDR_EQUAL(&config->addr6, &addr))
+		if (have_config(config, CONFIG_ADDR6) && IN6_ARE_ADDR_EQUAL(&config->addr6->addr.addr6, &addr))
 		  {
 		    prettyprint_time(daemon->dhcp_buff3, DECLINE_BACKOFF);
 		    inet_ntop(AF_INET6, &addr, daemon->addrbuff, ADDRSTRLEN);
