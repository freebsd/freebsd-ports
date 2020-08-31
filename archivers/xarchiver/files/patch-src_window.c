--- src/window.c.orig	2020-06-30 13:19:44 UTC
+++ src/window.c
@@ -1823,7 +1823,7 @@ ArchiveType xa_detect_archive_type (const gchar *filen
 		xa.type = XARCHIVETYPE_LZ4;
 	else if (memcmp(magic, "LZIP", 4) == 0)
 		xa.type = XARCHIVETYPE_LZIP;
-	else if (memcmp(magic, "\x5d\x00\x00\x80", 4) == 0)
+	else if (memcmp(magic, "\x5d\x00\x00", 3) == 0)
 		xa.type = XARCHIVETYPE_LZMA;
 	else if (memcmp(magic, "\211LZO", 4) == 0)
 		xa.type = XARCHIVETYPE_LZOP;
