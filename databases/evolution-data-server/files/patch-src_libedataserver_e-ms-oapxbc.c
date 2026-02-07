--- src/libedataserver/e-ms-oapxbc.c.orig	2025-01-03 18:00:44 UTC
+++ src/libedataserver/e-ms-oapxbc.c
@@ -42,6 +42,8 @@
 #define DBUS_BROKER_PATH "/com/microsoft/identity/broker1"
 #define AUTH_TYPE_OAUTH2 8
 
+#define UUID_STR_LEN		36
+
 struct _EMsOapxbc {
 	GObject parent_instance;
 
