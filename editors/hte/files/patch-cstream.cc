--- cstream.cc.orig	Mon Jul  1 02:08:48 2002
+++ cstream.cc	Wed Aug  4 18:09:28 2004
@@ -115,12 +115,13 @@
 	return true;
 }
 
-UINT	ht_compressed_stream::read(void *buf, UINT size)
+UINT	ht_compressed_stream::read(void *aBuf, UINT size)
 {
 	UINT ssize = size;
+	byte *buf = (byte *)aBuf;
 	while (size >= bufferpos) {
 		memcpy(buf, buffer+buffersize-bufferpos, bufferpos);
-		((byte *)buf) += bufferpos;
+		buf += bufferpos;
 		size -= bufferpos;
 		bufferpos = 0;
 		if (size) {
@@ -134,13 +135,14 @@
 	return ssize;
 }
 
-UINT	ht_compressed_stream::write(const void *buf, UINT size)
+UINT	ht_compressed_stream::write(const void *aBuf, UINT size)
 {
 	UINT ssize = size;
+	const byte *buf = (const byte *)aBuf;
 	while (bufferpos+size >= buffersize) {
 		memcpy(buffer+bufferpos, buf, buffersize-bufferpos);
 		size -= buffersize-bufferpos;
-		((byte *)buf) += buffersize-bufferpos;
+		buf += buffersize-bufferpos;
 		bufferpos = buffersize;
 		if (size) {
 			if (!flush_compressed()) return ssize - size;
