--- app/src/server.c.orig	2019-06-18 09:31:46 UTC
+++ app/src/server.c
@@ -15,7 +15,7 @@
 #define SOCKET_NAME "scrcpy"
 #define SERVER_FILENAME "scrcpy-server.jar"
 
-#define DEFAULT_SERVER_PATH PREFIX "/share/scrcpy/" SERVER_FLENAME
+#define DEFAULT_SERVER_PATH PREFIX "/share/scrcpy/" SERVER_FILENAME
 #define DEVICE_SERVER_PATH "/data/local/tmp/" SERVER_FILENAME
 
 static const char *
