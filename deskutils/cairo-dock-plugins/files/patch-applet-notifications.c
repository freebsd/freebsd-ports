--- logout/src/applet-notifications.c.orig	2012-03-10 14:47:11.714017314 +0200
+++ logout/src/applet-notifications.c	2012-03-10 14:47:23.824032902 +0200
@@ -26,7 +26,7 @@
 #include "applet-struct.h"
 #include "applet-notifications.h"
 
-#define GUEST_SESSION_LAUNCHER "/usr/share/gdm/guest-session/guest-session-launch"
+#define GUEST_SESSION_LAUNCHER "/usr/local/share/gdm/guest-session/guest-session-launch"
 
 
 static void _logout (void)
