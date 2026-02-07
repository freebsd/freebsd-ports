--- server/gam_subscription.c.orig	2011-09-17 11:17:22.000000000 +0200
+++ server/gam_subscription.c	2011-09-17 11:17:44.000000000 +0200
@@ -141,7 +141,7 @@ gam_subscription_pathlen(GamSubscription
  * @param sub the GamSubscription
  * @returns The path being monitored.  It should not be freed.
  */
-G_CONST_RETURN char *
+const char *
 gam_subscription_get_path(GamSubscription * sub)
 {
     if (sub == NULL)
