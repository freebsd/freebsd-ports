--- tools/osmpbf-outline.cpp.orig	2021-01-06 13:47:22 UTC
+++ tools/osmpbf-outline.cpp
@@ -10,6 +10,11 @@
 // zlib compression is used inside the pbf blobs
 #include <zlib.h>
 
+#ifndef WIN32
+	// used for isatty
+	#include <unistd.h>
+#endif
+
 // netinet or winsock2 provides the network-byte-order conversion function
 #ifdef D_HAVE_WINSOCK
     #include <winsock2.h>
