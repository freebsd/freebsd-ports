--- CorsixTH/Src/iso_fs.cpp.orig	2015-09-18 21:09:59 UTC
+++ CorsixTH/Src/iso_fs.cpp
@@ -31,6 +31,7 @@ SOFTWARE.
 #ifdef CORSIX_TH_HAS_ALLOCA_H
 #include <alloca.h>
 #endif
+#include <cstdlib>
 #include <algorithm>
 
 IsoFilesystem::IsoFilesystem()
