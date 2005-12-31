--- shell/main.c.orig	Sat Dec 31 14:09:43 2005
+++ shell/main.c	Sat Dec 31 14:09:54 2005
@@ -266,7 +266,7 @@ main (int argc, char **argv)
 					G_TYPE_STRING,
 					"org.gnome.Rhythmbox",
 					G_TYPE_UINT,
-					DBUS_NAME_FLAG_PROHIBIT_REPLACEMENT,
+					DBUS_NAME_FLAG_DO_NOT_QUEUE,
 					G_TYPE_INVALID,
 					G_TYPE_UINT,
 					&request_name_reply,
