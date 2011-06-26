--- src/conf.c.orig	2011-02-24 13:16:42.000000000 +0900
+++ src/conf.c	2011-02-24 13:17:50.000000000 +0900
@@ -40,7 +40,7 @@
 
 static config_t configuration;
 
-#define DEFAULT_CONFIG "/etc/umurmur.conf"
+#define DEFAULT_CONFIG "/usr/local/etc/umurmur/umurmur.conf"
 #define DEFAULT_WELCOME "Welcome to uMurmur!"
 #define DEFAULT_MAX_CLIENTS 10
 #define DEFAULT_MAX_BANDWIDTH 48000
@@ -73,23 +73,23 @@
 	case CERTIFICATE:
 		setting = config_lookup(&configuration, "certificate");
 		if (!setting)
-			return "/etc/umurmur/certificate.crt";
+			return "/usr/local/etc/umurmur/certificate.crt";
 		else {
 			if ((strsetting = config_setting_get_string(setting)) != NULL)
 				return strsetting;
 			else
-				return "/etc/umurmur/certificate.crt";
+				return "/usr/local/etc/umurmur/certificate.crt";
 		}
 		break;
 	case KEY:
 		setting = config_lookup(&configuration, "private_key");
 		if (!setting)
-			return "/etc/umurmur/private_key.key";
+			return "/usr/local/etc/umurmur/private_key.key";
 		else {
 			if ((strsetting = config_setting_get_string(setting)) != NULL)
 				return strsetting;
 			else
-				return "/etc/umurmur/private_key.key";
+				return "/usr/local/etc/umurmur/private_key.key";
 		}
 		break;
 	case PASSPHRASE:
