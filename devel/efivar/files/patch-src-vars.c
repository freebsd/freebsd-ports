--- src/vars.c.orig	2015-01-19 15:36:23.000000000 +0100
+++ src/vars.c	2015-01-19 15:36:36.000000000 +0100
@@ -94,7 +94,7 @@ vars_get_variable_size(efi_guid_t guid, 
 
 	char *path = NULL;
 	int rc = asprintf(&path, VARS_PATH "%s-"GUID_FORMAT"/size",
-			  name, guid.a, guid.b, guid.c, bswap_16(guid.d),
+			  name, guid.a, guid.b, guid.c, bswap16(guid.d),
 			  guid.e[0], guid.e[1], guid.e[2], guid.e[3],
 			  guid.e[4], guid.e[5]);
 	if (rc < 0)
@@ -146,7 +146,7 @@ vars_get_variable(efi_guid_t guid, const
 	size_t bufsize = -1;
 	char *path;
 	int rc = asprintf(&path, VARS_PATH "%s-" GUID_FORMAT "/raw_var",
-			  name, guid.a, guid.b, guid.c, bswap_16(guid.d),
+			  name, guid.a, guid.b, guid.c, bswap16(guid.d),
 			  guid.e[0], guid.e[1], guid.e[2],
 			  guid.e[3], guid.e[4], guid.e[5]);
 	if (rc < 0)
@@ -193,7 +193,7 @@ vars_del_variable(efi_guid_t guid, const
 	int ret = -1;
 	char *path;
 	int rc = asprintf(&path, VARS_PATH "%s-" GUID_FORMAT "/raw_var",
-			  name, guid.a, guid.b, guid.c, bswap_16(guid.d),
+			  name, guid.a, guid.b, guid.c, bswap16(guid.d),
 			  guid.e[0], guid.e[1], guid.e[2],
 			  guid.e[3], guid.e[4], guid.e[5]);
 	if (rc < 0)
@@ -280,7 +280,7 @@ vars_chmod_variable(efi_guid_t guid, con
 
 	char *path;
 	int rc = asprintf(&path, VARS_PATH "%s-" GUID_FORMAT,
-			  name, guid.a, guid.b, guid.c, bswap_16(guid.d),
+			  name, guid.a, guid.b, guid.c, bswap16(guid.d),
 			  guid.e[0], guid.e[1], guid.e[2], guid.e[3],
 			  guid.e[4], guid.e[5]);
 	if (rc < 0)
@@ -312,7 +312,7 @@ vars_set_variable(efi_guid_t guid, const
 
 	char *path;
 	int rc = asprintf(&path, VARS_PATH "%s-" GUID_FORMAT "/data",
-			  name, guid.a, guid.b, guid.c, bswap_16(guid.d),
+			  name, guid.a, guid.b, guid.c, bswap16(guid.d),
 			  guid.e[0], guid.e[1], guid.e[2], guid.e[3],
 			  guid.e[4], guid.e[5]);
 	if (rc < 0)
