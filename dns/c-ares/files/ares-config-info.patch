Description: Add the ares_get_config() routine used by Unreal IRCd.
 Originally taken from the Unreal IRCd distribution, later modified
 by me to properly support IPv6 nameserver addresses since c-ares-1.7.1.
Origin: the Unreal IRCd distribution
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: no
Last-Update: 2010-12-19

--- ares.h.orig
+++ ares.h
@@ -260,6 +260,14 @@
   int nsort;
 };
 
+/** Public available config (readonly) interface for ares_get_config(). */
+struct ares_config_info {
+	int timeout;
+	int tries;
+	int numservers;
+	char **servers;
+};
+
 struct hostent;
 struct timeval;
 struct sockaddr;
@@ -530,6 +538,8 @@
 CARES_EXTERN int ares_get_servers(ares_channel channel,
                                   struct ares_addr_node **servers);
 
+CARES_EXTERN int ares_get_config(struct ares_config_info *d, ares_channel c);
+
 #ifdef  __cplusplus
 }
 #endif
--- ares_init.c.orig	2013-02-17 11:44:02.000000000 -0500
+++ ares_init.c	2013-05-15 13:43:31.000000000 -0400
@@ -1875,6 +1875,36 @@
 }
 #endif  /* !WIN32 & !WATT32 & !ANDROID & !__ANDROID__ */
 
+int ares_get_config(struct ares_config_info *d, ares_channel c)
+{
+	int i;
+	const char *p;
+	char tmp[sizeof("ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255")];
+
+	memset(d, 0, sizeof(struct ares_config_info));
+
+	d->timeout = c->timeout;
+	d->tries = c->tries;
+	d->numservers = c->nservers;
+	d->servers = calloc(sizeof(char *), c->nservers);
+	for (i = 0; i < c->nservers; i++)
+	{
+		if (c->servers[i].addr.family == AF_INET)
+			p = ares_inet_ntop(c->servers[i].addr.family,
+			    (const char *)&c->servers[i].addr.addrV4,
+			    tmp, sizeof(tmp));
+		else if (c->servers[i].addr.family == AF_INET6)
+			p = ares_inet_ntop(c->servers[i].addr.family,
+			    (const char *)&c->servers[i].addr.addrV6,
+			    tmp, sizeof(tmp));
+		else
+			p = NULL;
+		d->servers[i] = p ? strdup(p) : NULL;
+	}
+
+	return ARES_SUCCESS;
+}
+
 /* initialize an rc4 key. If possible a cryptographically secure random key
    is generated using a suitable function (for example win32's RtlGenRandom as
    described in
