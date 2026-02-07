--- src/cfg.h.orig	2005-07-18 14:15:59 UTC
+++ src/cfg.h
@@ -74,7 +74,7 @@ enum mode {MODE_COMMENT, MODE_INDENT, MO
 #ifdef SYSCONFDIR
 #define GLOBAL_CONFIG_FILE SYSCONFDIR "/tpbrc"
 #else /* SYSCONFDIR */
-#define GLOBAL_CONFIG_FILE "/etc/tpbrc"
+#define GLOBAL_CONFIG_FILE "%%PREFIX%%/etc/tpbrc"
 #endif /* SYSCONFDIR */
 #define PRIVATE_CONFIG_FILE ".tpbrc"
 
