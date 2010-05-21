--- ./libtardy/tar/output/filter/gzip.cc.orig	2010-03-10 03:50:43.000000000 +0100
+++ ./libtardy/tar/output/filter/gzip.cc	2010-05-21 15:20:02.000000000 +0200
@@ -21,6 +21,10 @@
 #include <libtardy/ac/string.h>
 #include <libtardy/tar/output/filter/gzip.h>
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
+
 #ifndef Z_BUFSIZE
 #ifdef MAXSEG_64K
 #define Z_BUFSIZE 4096 // minimize memory usage for 16-bit DOS
