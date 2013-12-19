--- apps/tqsl.cpp.orig	2013-12-12 15:52:46.737002435 -0500
+++ apps/tqsl.cpp	2013-12-12 15:52:12.740004212 -0500
@@ -71,7 +71,7 @@
 #endif
 #include <zlib.h>
 #include <openssl/opensslv.h> // only for version info!
-#include <db.h> //only for version info!
+#include <db5/db.h> //only for version info!
 #include "tqslwiz.h"
 #include "qsodatadialog.h"
 #include "tqslerrno.h"
@@ -2016,7 +2016,7 @@
 	} else {
 		//compress the upload
 		string compressed;
-		size_t compressedSize=compressToBuf(compressed, (const char*)signedOutput.mb_str());
+		ssize_t compressedSize=compressToBuf(compressed, (const char*)signedOutput.mb_str());
 		//ofstream f; f.open("testzip.tq8", ios::binary); f<<compressed; f.close(); //test of compression routine
 		if (compressedSize<0) { 
 			wxLogMessage(wxT("Error compressing before upload")); 
