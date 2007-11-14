--- ircd/s_auth.c.orig	2007-11-14 03:07:39.000000000 +0600
+++ ircd/s_auth.c	2007-11-14 03:07:56.000000000 +0600
@@ -260,7 +260,7 @@
 				{
 				    iauth_conf = iauth_conf->next;
 				    MyFree(ectmp->line);
-				    MyFree((void *)ectmp);
+				    MyFree(ectmp);
 				}
 			    /* little lie.. ;) */
 			    sendto_flag(SCH_AUTH, "New iauth configuration.");
@@ -287,7 +287,7 @@
 				{
 				    iauth_stats = iauth_stats->next;
 				    MyFree(ectmp->line);
-				    MyFree((void *)ectmp);
+				    MyFree(ectmp);
 				}
 			    iauth_stats = (aExtData *)
 				    MyMalloc(sizeof(aExtData));
