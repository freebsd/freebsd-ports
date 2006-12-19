--- cfcreate.h.orig	Tue Dec 19 20:09:01 2006
+++ cfcreate.h	Tue Dec 19 20:09:09 2006
@@ -211,7 +211,7 @@
 		int process_block(const byte* data, word datalen);
 		int read_block(istream& in, byte* &buf, int& bytesread);
 		int compress_block(byte* &dest, word &destlen, byte* src, word srclen);
-		CHECKSUM cfc_folderinfo::CSUMCompute(byte* pb, unsigned cb, CHECKSUM seed);
+		CHECKSUM CSUMCompute(byte* pb, unsigned cb, CHECKSUM seed);
 	public:
 		cfc_folderinfo() { clear_variables(); }
 		virtual ~cfc_folderinfo() { free_buffers(); }
