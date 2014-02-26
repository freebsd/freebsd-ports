--- connectivity/source/inc/dbase/dindexnode.hxx.orig	2013-12-11 01:11:21.000000000 +0900
+++ connectivity/source/inc/dbase/dindexnode.hxx	2014-01-29 16:48:39.000000000 +0900
@@ -26,7 +26,12 @@
 #include <tools/ref.hxx>
 
 #define NODE_NOTFOUND 0xFFFF
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#define DINDEX_PAGE_SIZE PAGE_SIZE
+#else
 #define DINDEX_PAGE_SIZE 512
+#endif
 
 namespace connectivity
 {
