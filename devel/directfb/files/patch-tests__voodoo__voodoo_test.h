--- tests/voodoo/voodoo_test.h.orig	2016-06-08 05:59:40 UTC
+++ tests/voodoo/voodoo_test.h
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
