--- htle.cc.orig	Thu Oct 10 03:32:50 2002
+++ htle.cc	Wed Aug  4 18:14:34 2004
@@ -475,19 +475,20 @@
 	return false;
 }
 
-UINT ht_le_page_file::read(void *buf, UINT size)
+UINT ht_le_page_file::read(void *aBuf, UINT size)
 {
 	FILEOFS mofs;
 	UINT msize;
 	int c = 0;
 	while (size) {
 		UINT s = size;
+		byte *buf = (byte *)aBuf;
 		if (!map_ofs(ofs, &mofs, &msize)) break;
 		if (s>msize) s = msize;
 		streamfile->seek(mofs);
 		s = streamfile->read(buf, s);
 		if (!s) break;
-		((byte*)buf) += s;
+		buf += s;
 		size -= s;
 		c += s;
 		ofs += s;
@@ -546,17 +547,18 @@
 	return ht_layer_streamfile::vcntl(cmd, vargs);
 }
 
-UINT ht_le_page_file::write(const void *buf, UINT size)
+UINT ht_le_page_file::write(const void *aBuf, UINT size)
 {
 	FILEOFS mofs;
 	UINT msize;
 	int c = 0;
 	while (size) {
 		UINT s = size;
+		const byte *buf = (const byte *)aBuf;
 		if (!map_ofs(ofs, &mofs, &msize)) break;
 		if (s>msize) s = msize;
 		streamfile->seek(mofs);
-		((byte*)buf) += streamfile->write(buf, s);
+		buf += streamfile->write(buf, s);
 		size -= s;
 		c += s;
 		ofs += s;
