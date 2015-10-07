--- helpers.hh.orig	2010-11-23 21:22:51 UTC
+++ helpers.hh
@@ -35,6 +35,14 @@
 
 #include <stdint.h>
 
+#if defined __FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version < 1000034
+extern "C" {
+#include <mathl.h>
+}
+#endif
+#endif
 
 
 
