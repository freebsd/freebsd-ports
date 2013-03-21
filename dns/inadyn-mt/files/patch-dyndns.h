diff --git src/dyndns.h src/dyndns.h
index ed854c1..7513275 100644
--- src/dyndns.h
+++ src/dyndns.h
@@ -106,11 +106,11 @@ typedef enum
 
 /*test values*/
 #define DYNDNS_DEFAULT_DEBUG_LEVEL	LOG_WARNING
-#define DYNDNS_MT_DEFAULT_CONFIG_FILE_OLD		"/etc/inadyn-mt/inadyn-mt.conf"
-#define DYNDNS_MT_DEFAULT_CONFIG_FILE			"/etc/inadyn-mt.conf"
+#define DYNDNS_MT_DEFAULT_CONFIG_FILE_OLD		"%%PREFIX%%/etc/inadyn-mt/inadyn-mt.conf"
+#define DYNDNS_MT_DEFAULT_CONFIG_FILE			"%%PREFIX%%/etc/inadyn-mt.conf"
 
 /*inadyn backward compatibility*/
-#define DYNDNS_DEFAULT_CONFIG_FILE			"/etc/inadyn.conf"
+#define DYNDNS_DEFAULT_CONFIG_FILE			"%%PREFIX%%/etc/inadyn.conf"
 
 #define DYNDNS_DEFAULT_CACHE_PREFIX			"/tmp/"
 #define DYNDNS_DEFAULT_IP_FILE				"inadyn_ip.cache"
