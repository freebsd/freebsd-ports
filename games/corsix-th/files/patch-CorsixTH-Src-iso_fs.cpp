--- CorsixTH/Src/iso_fs.cpp.orig	2013-09-17 17:59:28.434946572 +0200
+++ CorsixTH/Src/iso_fs.cpp	2013-09-17 18:00:15.533944173 +0200
@@ -30,6 +30,7 @@
 #ifdef CORSIX_TH_HAS_ALLOCA_H
 #include <alloca.h>
 #endif
+#include <cstdlib>
 #include <algorithm>
 
 IsoFilesystem::IsoFilesystem()
