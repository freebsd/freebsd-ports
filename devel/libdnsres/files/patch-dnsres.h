--- dnsres.h.orig	Fri Feb 17 16:51:37 2006
+++ dnsres.h	Fri Feb 17 16:52:14 2006
@@ -431,6 +431,8 @@
 int		dnsres_net_addrcmp(struct sockaddr *, struct sockaddr *);
 int		dnsres_getrrsetbyname(const char *, unsigned int, unsigned int, unsigned int, struct dnsres_rrsetinfo **);
 void		dnsres_freerrset(struct dnsres_rrsetinfo *);
+int		dnsres_init(struct dnsres *);
+void		dnsres_cancel_lookup(void *);
 __END_DECLS
 
 /*
@@ -502,8 +504,5 @@
 	struct dnsres_hostent_state hostent_state;
 	struct dnsres_servent_state servent_state;
 };
-
-int dnsres_init(struct dnsres *_resp);
-void dnsres_cancel_lookup(void *handle);
 
 #endif /* _DNSRES_H_ */
