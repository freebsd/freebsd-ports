--- src/utils/BamTools/include/SamHeader.hpp.orig	2021-01-24 16:15:06 UTC
+++ src/utils/BamTools/include/SamHeader.hpp
@@ -7,6 +7,7 @@
 #include <string.h>
 #include <api/BamAux.h>
 #include <stdlib.h>
+#include <sysexits.h>
 
 
 #ifdef WITH_HTS_CB_API
@@ -29,7 +30,11 @@ namespace htslib_future {
 		ops.cb_data = buffer;
 		samFile* fp = hts_open_callback(NULL, &ops, "w");
 
-		sam_hdr_write(fp, hdr);
+		if ( sam_hdr_write(fp, hdr) != 0 )
+		{
+			fputs("sam_hdr_rebuild: Error: sam_hdr_write() failed.\n", stderr);
+			exit(EX_IOERR);
+		}
 
 		hts_close(fp);
 
