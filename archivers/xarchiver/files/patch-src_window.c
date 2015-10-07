--- src/window.c.orig	2014-09-28 20:42:37 UTC
+++ src/window.c
@@ -1130,7 +1130,7 @@ XArchiveType xa_detect_archive_type (gch
 		xx = XARCHIVETYPE_BZIP2;
 	else if (memcmp ( magic,"\x1f\x8b",2) == 0 || memcmp ( magic,"\x1f\x9d",2) == 0)
 		xx = XARCHIVETYPE_GZIP;
-	else if (memcmp ( magic,"\x5d\x00\x00\x80",4) == 0)
+	else if (memcmp ( magic,"\x5d\x00\x00",3) == 0)
 		xx = XARCHIVETYPE_LZMA;
 	else if (memcmp ( magic,"\xfd\x37\x7a\x58\x5a",5) == 0)
 		xx = XARCHIVETYPE_XZ;
