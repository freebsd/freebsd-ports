--- connectivity/source/inc/dbase/dindexnode.hxx.orig	2013-06-11 05:33:38.000000000 -0400
+++ connectivity/source/inc/dbase/dindexnode.hxx	2013-06-25 13:44:38.000000000 -0400
@@ -26,7 +26,11 @@
 #include <tools/ref.hxx>
 
 #define NODE_NOTFOUND 0xFFFF
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#else
 #define PAGE_SIZE 512
+#endif
 
 namespace connectivity
 {
