--- ppp/ppp_l2tp_server.c.orig	2009-05-13 21:36:03 UTC
+++ ppp/ppp_l2tp_server.c
@@ -70,7 +70,7 @@ struct ppp_l2tp_peer {
 	struct ppp_channel		*chan;		/* pointer to channel */
 	struct ppp_auth_config		auth;		/* auth config */
 	char				node[32];		/* node path */
-	char				hook[NG_HOOKLEN + 1];	/* node hook */
+	char				hook[NG_HOOKSIZ];	/* node hook */
 	char				logname[32];	/* peer logname */
 	struct in_addr			ip;		/* peer ip address */
 	u_int16_t			port;		/* peer port */
@@ -503,7 +503,7 @@ ppp_l2tp_server_sock_event(void *arg)
 	struct sockaddr_in sin;
 	const size_t bufsize = 8192;
 	u_int16_t *buf = NULL;
-	char hook[NG_HOOKLEN + 1];
+	char hook[NG_HOOKSIZ];
 	socklen_t sin_len;
 	char namebuf[64];
 	ng_ID_t node_id;
