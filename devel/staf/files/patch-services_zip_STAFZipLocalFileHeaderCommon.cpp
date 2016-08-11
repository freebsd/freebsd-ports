--- services/zip/STAFZipLocalFileHeaderCommon.cpp.orig	2016-06-01 19:08:03 UTC
+++ services/zip/STAFZipLocalFileHeaderCommon.cpp
@@ -12,7 +12,6 @@
 #include <map>
 
 #include "zlib.h"
-#include "zutil.h"
 
 #include "STAFZip.h"
 #include "STAFZipUtil.h"
@@ -366,7 +365,7 @@ STAFRC_t STAFZipLocalFileHeader::flush(F
         uInt level = 9;
 
         err = deflateInit2(&stream, level,
-               Z_DEFLATED, -MAX_WBITS, DEF_MEM_LEVEL, 0);
+               Z_DEFLATED, -MAX_WBITS, 8, Z_DEFAULT_STRATEGY);
 
 
         if (err != Z_OK)
