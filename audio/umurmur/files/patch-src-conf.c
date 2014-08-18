--- src/conf.c.orig	2014-08-07 23:37:03.000000000 -0700
+++ src/conf.c	2014-08-14 11:47:27.000000000 -0700
@@ -89,23 +89,23 @@
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
