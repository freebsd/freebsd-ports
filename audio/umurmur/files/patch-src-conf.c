--- src/conf.c.old	2011-12-04 19:11:54.718388035 +0200
+++ src/conf.c	2011-12-04 19:13:08.845299535 +0200
@@ -87,23 +87,23 @@
 	case CERTIFICATE:
 		setting = config_lookup(&configuration, "certificate");
 		if (!setting)
-			return "/etc/umurmur/certificate.crt";
+			return "%%PREFIX%%/etc/umurmur/certificate.crt";
 		else {
 			if ((strsetting = config_setting_get_string(setting)) != NULL)
 				return strsetting;
 			else
-				return "/etc/umurmur/certificate.crt";
+				return "%%PREFIX%%/etc/umurmur/certificate.crt";
 		}
 		break;
 	case KEY:
 		setting = config_lookup(&configuration, "private_key");
 		if (!setting)
-			return "/etc/umurmur/private_key.key";
+			return "%%PREFIX%%/etc/umurmur/private_key.key";
 		else {
 			if ((strsetting = config_setting_get_string(setting)) != NULL)
 				return strsetting;
 			else
-				return "/etc/umurmur/private_key.key";
+				return "%%PREFIX%%/etc/umurmur/private_key.key";
 		}
 		break;
 	case PASSPHRASE:
