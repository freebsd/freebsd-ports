--- ./tests/voodoo/voodoo_test.h.orig	2010-12-03 16:44:12.000000000 +0100
+++ ./tests/voodoo/voodoo_test.h	2010-12-03 16:44:12.000000000 +0100
@@ -0,0 +1,10 @@
+#ifndef __VOODOO_TEST_H__
+#define __VOODOO_TEST_H__
+
+typedef enum {
+     VOODOO_TEST_INCREASE,
+     VOODOO_TEST_QUERY
+} VoodooTestCall;
+
+#endif
+
