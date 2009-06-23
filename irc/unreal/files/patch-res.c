--- src/res.c	2006-09-19 15:45:18.000000000 +0300
+++ src/res.c	2009-06-17 17:50:18.000000000 +0300
@@ -48,10 +48,15 @@
 
 #include <res.h>
 
+/* Prevent crashes due to invalid prototype/ABI */
+#if ARES_VERSION < 0x010600
+ #error "You have an old c-ares version on your system and/or Unreals c-ares failed to compile!"
+#endif
+
 /* Forward declerations */
-void unrealdns_cb_iptoname(void *arg, int status, struct hostent *he);
-void unrealdns_cb_nametoip_verify(void *arg, int status, struct hostent *he);
-void unrealdns_cb_nametoip_link(void *arg, int status, struct hostent *he);
+void unrealdns_cb_iptoname(void *arg, int status, int timeouts, struct hostent *he);
+void unrealdns_cb_nametoip_verify(void *arg, int status, int timeouts, struct hostent *he);
+void unrealdns_cb_nametoip_link(void *arg, int status, int timeouts, struct hostent *he);
 void unrealdns_delasyncconnects(void);
 static unsigned int unrealdns_haship(void *binaryip, int length);
 static void unrealdns_addtocache(char *name, void *binaryip, int length);
@@ -240,7 +245,7 @@
 #endif
 }
 
-void unrealdns_cb_iptoname(void *arg, int status, struct hostent *he)
+void unrealdns_cb_iptoname(void *arg, int status, int timeouts, struct hostent *he)
 {
 DNSReq *r = (DNSReq *)arg;
 DNSReq *newr;
@@ -290,7 +295,7 @@
 }
 
 
-void unrealdns_cb_nametoip_verify(void *arg, int status, struct hostent *he)
+void unrealdns_cb_nametoip_verify(void *arg, int status, int timeouts, struct hostent *he)
 {
 DNSReq *r = (DNSReq *)arg;
 aClient *acptr = r->cptr;
@@ -363,7 +368,7 @@
 	unrealdns_freeandremovereq(r);
 }
 
-void unrealdns_cb_nametoip_link(void *arg, int status, struct hostent *he)
+void unrealdns_cb_nametoip_link(void *arg, int status, int timeouts, struct hostent *he)
 {
 DNSReq *r = (DNSReq *)arg;
 int n;
@@ -390,9 +395,11 @@
 		/* fatal error while resolving */
 		sendto_realops("Unable to resolve hostname '%s', when trying to connect to server %s.",
 			r->name, r->linkblock->servername);
+		r->linkblock->refcount--;
 		unrealdns_freeandremovereq(r);
 		return;
 	}
+	r->linkblock->refcount--;
 
 #ifdef INET6
 	if (((he->h_length != 4) && (he->h_length != 16)) || !he->h_addr_list[0])
@@ -715,21 +722,34 @@
 	} else
 	if (*param == 'i') /* INFORMATION */
 	{
-		struct ares_config_info inf;
+		struct ares_options inf;
 		int i;
+		int optmask;
 		
-		ares_get_config(&inf, resolver_channel);
+		ares_save_options(resolver_channel, &inf, &optmask);
 
 		sendtxtnumeric(sptr, "****** DNS Configuration Information ******");
 		sendtxtnumeric(sptr, " c-ares version: %s",ares_version(NULL));
-		sendtxtnumeric(sptr, "        timeout: %d", inf.timeout);
-		sendtxtnumeric(sptr, "          tries: %d", inf.tries);
-		sendtxtnumeric(sptr, "   # of servers: %d", inf.numservers);
-		for (i = 0; i < inf.numservers; i++)
-			sendtxtnumeric(sptr, "      server #%d: %s", i+1, inf.servers[i] ? inf.servers[i] : "[???]");
-			
-		/* TODO: free or get memleak ! */
+
+		if(optmask & ARES_OPT_TIMEOUTMS)
+			sendtxtnumeric(sptr, "        timeout: %d", inf.timeout);
+		if(optmask & ARES_OPT_TRIES)
+			sendtxtnumeric(sptr, "          tries: %d", inf.tries);
+		if(optmask & ARES_OPT_SERVERS)
+		{
+			sendtxtnumeric(sptr, "   # of servers: %d", inf.nservers);
+			for (i = 0; i < inf.nservers; i++)
+				sendtxtnumeric(sptr, "      server #%d: %s", i+1, inet_ntoa(inf.servers[i]));	
+		}
+		if(optmask & ARES_OPT_DOMAINS)
+		{
+			sendtxtnumeric(sptr, "   # of search domains: %d", inf.ndomains);
+			for (i = 0; i < inf.ndomains; i++)
+				sendtxtnumeric(sptr, "      domain #%d: %s", i+1, inf.domains[i]);
+		}
 		sendtxtnumeric(sptr, "****** End of DNS Configuration Info ******");
+		
+		ares_destroy_options(&inf);
 	} else /* STATISTICS */
 	{
 		sendtxtnumeric(sptr, "DNS CACHE Stats:");
