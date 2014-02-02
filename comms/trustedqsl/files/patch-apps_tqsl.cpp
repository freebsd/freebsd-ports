--- apps/tqsl.cpp.orig	2013-10-20 20:33:20.000000000 -0400
+++ apps/tqsl.cpp	2014-01-26 10:20:28.036914222 -0500
@@ -71,7 +71,7 @@
 #endif
 #include <zlib.h>
 #include <openssl/opensslv.h> // only for version info!
-#include <db.h> //only for version info!
+#include <db5/db.h> //only for version info!
 #include "tqslwiz.h"
 #include "qsodatadialog.h"
 #include "tqslerrno.h"
@@ -1862,7 +1862,7 @@
 				return TQSL_EXIT_LIB_ERROR;
 			}
 		} else {
-			out<<output;
+			out<<output.mb_str();
 			if (out.fail()) {
 				tqsl_converterRollBack(conv);
 				tqsl_endConverter(&conv);
@@ -2016,7 +2016,7 @@
 	} else {
 		//compress the upload
 		string compressed;
-		size_t compressedSize=compressToBuf(compressed, (const char*)signedOutput.mb_str());
+		ssize_t compressedSize=compressToBuf(compressed, (const char*)signedOutput.mb_str());
 		//ofstream f; f.open("testzip.tq8", ios::binary); f<<compressed; f.close(); //test of compression routine
 		if (compressedSize<0) { 
 			wxLogMessage(wxT("Error compressing before upload")); 
