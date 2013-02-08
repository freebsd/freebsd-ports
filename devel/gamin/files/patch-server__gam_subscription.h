--- server/gam_subscription.h.orig	2011-09-17 11:15:00.000000000 +0200
+++ server/gam_subscription.h	2011-09-17 11:15:18.000000000 +0200
@@ -21,7 +21,7 @@ int                  gam_subscription_pa
 
 int                  gam_subscription_get_reqno    (GamSubscription *sub);
 
-G_CONST_RETURN char *gam_subscription_get_path     (GamSubscription *sub);
+const char          *gam_subscription_get_path     (GamSubscription *sub);
 
 GamListener         *gam_subscription_get_listener (GamSubscription *sub);
 
