--- gsettings/gconfsettingsbackend.c.orig	2010-11-14 12:54:57.000000000 -0500
+++ gsettings/gconfsettingsbackend.c	2010-11-14 12:55:08.000000000 -0500
@@ -924,5 +924,5 @@ gconf_settings_backend_register (GIOModu
   g_io_extension_point_implement (G_SETTINGS_BACKEND_EXTENSION_POINT_NAME,
                                   GCONF_TYPE_SETTINGS_BACKEND,
                                   "gconf",
-                                  -1);
+                                  10);
 }
