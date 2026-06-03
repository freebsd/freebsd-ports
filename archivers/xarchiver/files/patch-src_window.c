--- src/window.c.orig	2025-09-01 12:04:54 UTC
+++ src/window.c
@@ -1844,7 +1844,7 @@ ArchiveType xa_detect_archive_type (const gchar *filen
 	}
 	else if (memcmp(magic, "LZIP", 4) == 0)
 		xa.type = XARCHIVETYPE_LZIP;
-	else if (memcmp(magic, "\x5d\x00\x00\x80", 4) == 0)
+	else if (memcmp(magic, "\x5d\x00\x00", 3) == 0)
 		xa.type = XARCHIVETYPE_LZMA;
 	else if (memcmp(magic, "\211LZO", 4) == 0)
 		xa.type = XARCHIVETYPE_LZOP;
