--- ircd/m_help.c.orig	2008-08-04 02:55:42.000000000 +0000
+++ ircd/m_help.c
@@ -243,6 +243,7 @@ sendhelpfile(struct Client *sptr, const 
   send_reply(sptr, RPL_ENDOFHELP, topic);
 }
 
+void
 dohelp(struct Client *sptr, const char *hpath, char *topic)
 {
   char path[PATH_MAX + 1];
@@ -291,7 +292,7 @@ dohelp(struct Client *sptr, const char *
   sendhelpfile(sptr, path, topic);
 }
 
-int m_help(struct Client* cptr, struct Client* sptr, int parc, char* parv[])
+void m_help(struct Client* cptr, struct Client* sptr, int parc, char* parv[])
 {
   static time_t last_used = 0;
 
