--- src/alarm-applet.h.orig	2020-08-27 17:50:22 UTC
+++ src/alarm-applet.h
@@ -46,7 +46,7 @@ G_BEGIN_DECLS
 
 typedef struct _AlarmApplet AlarmApplet;
 
-GHashTable *app_command_map;
+extern GHashTable *app_command_map;
 
 void alarm_applet_label_update (AlarmApplet *applet);
 void alarm_applet_clear_alarms (AlarmApplet *applet);
