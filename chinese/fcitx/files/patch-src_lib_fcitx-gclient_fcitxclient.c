--- src/lib/fcitx-gclient/fcitxclient.c.orig	2012-09-19 14:25:18.000000000 +0800
+++ src/lib/fcitx-gclient/fcitxclient.c	2012-09-19 14:29:55.000000000 +0800
@@ -26,10 +26,14 @@
 #include "fcitxclient.h"
 #include "marshall.h"
 
+#ifdef _DEBUG
 #define fcitx_gclient_debug(...) g_log ("fcitx-client",       \
                                       G_LOG_LEVEL_DEBUG,    \
                                       __VA_ARGS__)
 
+#else
+#define fcitx_gclient_debug(...)
+#endif
 typedef struct _ProcessKeyStruct ProcessKeyStruct;
 
 struct _ProcessKeyStruct {
