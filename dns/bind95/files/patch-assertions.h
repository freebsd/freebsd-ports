--- lib/isc/include/isc/assertions.h.ISC	Wed Jan 17 15:42:19 2001
+++ lib/isc/include/isc/assertions.h	Tue Feb  6 22:20:19 2001
@@ -51,6 +51,12 @@
 #define ISC_CHECK_INVARIANT		1
 #endif
 
+/*
+  Turn off ISC debugging code to avoid a possible DOS attack
+  related to nmap TCP connect() scanning.
+*/
+#define ISC_CHECK_NONE
+
 #ifdef ISC_CHECK_NONE
 #define ISC_CHECK_REQUIRE		0
 #define ISC_CHECK_ENSURE		0
