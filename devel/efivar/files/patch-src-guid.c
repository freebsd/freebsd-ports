--- src/guid.c.orig	2015-01-19 15:37:01.000000000 +0100
+++ src/guid.c	2015-01-19 15:37:10.000000000 +0100
@@ -41,17 +41,17 @@ efi_guid_to_str(const efi_guid_t *guid, 
 
 	if (!sp) {
 		return snprintf(NULL, 0, GUID_FORMAT,
-				guid->a, guid->b, guid->c, bswap_16(guid->d),
+				guid->a, guid->b, guid->c, bswap16(guid->d),
 				guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 				guid->e[4], guid->e[5]);
 	} else if (sp && *sp) {
 		return snprintf(*sp, GUID_LENGTH_WITH_NUL, GUID_FORMAT,
-				guid->a, guid->b, guid->c, bswap_16(guid->d),
+				guid->a, guid->b, guid->c, bswap16(guid->d),
 				guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 				guid->e[4], guid->e[5]);
 	} else {
 		rc = asprintf(&ret, GUID_FORMAT,
-				guid->a, guid->b, guid->c, bswap_16(guid->d),
+				guid->a, guid->b, guid->c, bswap16(guid->d),
 				guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 				guid->e[4], guid->e[5]);
 		if (rc >= 0)
@@ -161,17 +161,17 @@ efi_guid_to_id_guid(const efi_guid_t *gu
 	}
 	if (!sp) {
 		return snprintf(NULL, 0, "{"GUID_FORMAT"}",
-				guid->a, guid->b, guid->c, bswap_16(guid->d),
+				guid->a, guid->b, guid->c, bswap16(guid->d),
 				guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 				guid->e[4], guid->e[5]);
 	} else if (sp && *sp) {
 		return snprintf(*sp, GUID_LENGTH_WITH_NUL+2, "{"GUID_FORMAT"}",
-				guid->a, guid->b, guid->c, bswap_16(guid->d),
+				guid->a, guid->b, guid->c, bswap16(guid->d),
 				guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 				guid->e[4], guid->e[5]);
 	}
 	rc = asprintf(&ret, "{"GUID_FORMAT"}",
-			guid->a, guid->b, guid->c, bswap_16(guid->d),
+			guid->a, guid->b, guid->c, bswap16(guid->d),
 			guid->e[0], guid->e[1], guid->e[2], guid->e[3],
 			guid->e[4], guid->e[5]);
 	if (rc >= 0)
