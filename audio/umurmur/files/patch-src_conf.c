--- src/conf.c.orig	2021-03-21 20:49:04 UTC
+++ src/conf.c
@@ -90,23 +90,23 @@ const char *getStrConf(param_t param)
 		case CERTIFICATE:
 			setting = config_lookup(&configuration, "certificate");
 			if (!setting)
-				return "/etc/umurmur/certificate.crt";
+				return "%%PREFIX%%/etc/umurmur/certificate.crt";
 			else {
 				if ((strsetting = config_setting_get_string(setting)) != NULL)
 					return strsetting;
 				else
-					return "/etc/umurmur/certificate.crt";
+					return "%%PREFIX%%/etc/umurmur/certificate.crt";
 			}
 			break;
 		case KEY:
 			setting = config_lookup(&configuration, "private_key");
 			if (!setting)
-				return "/etc/umurmur/private_key.key";
+				return "%%PREFIX%%/etc/umurmur/private_key.key";
 			else {
 				if ((strsetting = config_setting_get_string(setting)) != NULL)
 					return strsetting;
 				else
-					return "/etc/umurmur/private_key.key";
+					return "%%PREFIX%%/etc/umurmur/private_key.key";
 			}
 			break;
 		case CAPATH:
