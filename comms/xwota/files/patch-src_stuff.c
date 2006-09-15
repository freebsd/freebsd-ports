--- src/stuff.c.orig	Wed Sep 13 15:23:19 2006
+++ src/stuff.c	Wed Sep 13 15:24:18 2006
@@ -22,6 +22,7 @@
 #include "global.h"
 #include "stuff.h"
 
+void private_messages_log(gchar *date_msg_log,gchar *time_log,gchar *from,gchar *to,gchar *text);
 
 
 int load_preferences()
