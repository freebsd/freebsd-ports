--- rtengine/imagedata.cc.orig	2010-01-10 18:54:02.000000000 -0800
+++ rtengine/imagedata.cc	2010-01-10 18:59:50.000000000 -0800
@@ -19,7 +19,9 @@
 #include <imagedata.h>
 #include <iptcpairs.h>
 #include <glib/gstdio.h>
+#ifdef RAWZOR_SUPPORT
 #include <rwz_sdk.h>
+#endif
 
 using namespace rtengine;
 
