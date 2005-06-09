--- src/cfg.h.orig	Mon May 30 00:06:16 2005
+++ src/cfg.h	Mon May 30 00:06:32 2005
@@ -67,7 +67,7 @@
 #ifdef SYSCONFDIR
 #define GLOBAL_CONFIG_FILE SYSCONFDIR "/tpbrc"
 #else /* SYSCONFDIR */
-#define GLOBAL_CONFIG_FILE "/etc/tpbrc"
+#define GLOBAL_CONFIG_FILE "%%PREFIX%%/etc/tpbrc"
 #endif /* SYSCONFDIR */
 #define PRIVATE_CONFIG_FILE ".tpbrc"
 
