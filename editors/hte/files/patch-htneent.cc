--- htneent.cc.orig	2016-12-06 20:36:25 UTC
+++ htneent.cc
@@ -57,7 +57,7 @@ static ht_view *htneentrypoints_init(Bounds *b, File *
 	NE_ENTRYPOINT_HEADER e;
 
 	uint32 index = 1;
-	while (o + sizeof e < h+ne_shared->hdr.enttab+ne_shared->hdr.cbenttab) {
+	while ((o + sizeof e) < h+ne_shared->hdr.enttab+ne_shared->hdr.cbenttab) {
 		file->seek(o);
 		file->read(&e, sizeof e);
 		createHostStruct(&e, NE_ENTRYPOINT_HEADER_struct, little_endian);
