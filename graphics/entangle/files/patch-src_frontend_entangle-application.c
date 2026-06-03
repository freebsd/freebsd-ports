--- src/frontend/entangle-application.c.orig	2017-10-10 21:07:59 UTC
+++ src/frontend/entangle-application.c
@@ -517,7 +517,7 @@ static void entangle_application_init(EntangleApplicat
     priv->activeCameras = entangle_camera_list_new_active();
     priv->supportedCameras = entangle_camera_list_new_supported();
 
-    g_irepository_require(g_irepository_get_default(),
+    gi_repository_require(gi_repository_dup_default(),
                           "Peas", "1.0", 0, NULL);
 
     userdir = g_build_filename(g_get_user_config_dir(), "entangle/plugins", NULL);
