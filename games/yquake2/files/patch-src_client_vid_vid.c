--- src/client/vid/vid.c.orig	2025-09-14 05:35:31 UTC
+++ src/client/vid/vid.c
@@ -319,7 +319,13 @@ VID_GetRendererLibPath(const char *renderer, char *pat
 static void
 VID_GetRendererLibPath(const char *renderer, char *path, size_t len)
 {
-	snprintf(path, len, "%sref_%s.%s", Sys_GetBinaryDir(), renderer, lib_ext);
+	char *next_path = NULL;
+
+	while ((next_path = FS_GetNextRawPath(next_path)) != NULL) {
+		snprintf(path, len, "%s/ref_%s.%s", next_path, renderer, lib_ext);
+		if (Sys_IsFile(path))
+			break;
+	}
 }
 
 /*
