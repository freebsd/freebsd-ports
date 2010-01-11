--- rtengine/myfile.cc.orig	2010-01-10 19:00:52.000000000 -0800
+++ rtengine/myfile.cc	2010-01-10 19:01:08.000000000 -0800
@@ -19,7 +19,9 @@
 #include <myfile.h>
 #include <cstdarg>
 #include <glibmm.h>
+#ifdef RAWZOR_SUPPORT
 #include <rwz_sdk.h>
+#endif
 
 IMFILE* fopen (const char* fname) {
 
