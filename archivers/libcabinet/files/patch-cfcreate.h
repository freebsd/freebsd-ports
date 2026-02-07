--- cfcreate.h.orig	1999-10-24 11:29:53 UTC
+++ cfcreate.h
@@ -20,6 +20,8 @@
 #include "cffile.h"
 #include "zlib.h"
 
+using std::fstream;
+
 #ifdef unix
 #include <unistd.h>
 #endif
@@ -211,7 +213,7 @@ class cfc_folderinfo : public ObjectBase
 		int process_block(const byte* data, word datalen);
 		int read_block(istream& in, byte* &buf, int& bytesread);
 		int compress_block(byte* &dest, word &destlen, byte* src, word srclen);
-		CHECKSUM cfc_folderinfo::CSUMCompute(byte* pb, unsigned cb, CHECKSUM seed);
+		CHECKSUM CSUMCompute(byte* pb, unsigned cb, CHECKSUM seed);
 	public:
 		cfc_folderinfo() { clear_variables(); }
 		virtual ~cfc_folderinfo() { free_buffers(); }
