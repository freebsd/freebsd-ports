--- src/loader/loader.cc.orig	Sun May 18 13:41:35 2003
+++ src/loader/loader.cc	Sun May 18 13:42:24 2003
@@ -32,6 +32,9 @@
 #include<zlib.h>
 #endif
 
+#ifdef __FreeBSD__
+#define __GNU_LIBRARY__
+#endif
 #include <getopt.h>
 
 string path[]=
