--- dns.c.orig	2015-12-16 00:46:50 UTC
+++ dns.c
@@ -41,9 +41,11 @@
 #define ISC_BUFFER_USEINLINE
 
 #include <isc/base64.h>
+#include <isc/boolean.h>
 #include <isc/buffer.h>
 #include <isc/hmacmd5.h>
 #include <isc/hmacsha.h>
+#include <isc/int.h>
 #include <isc/lex.h>
 #include <isc/mem.h>
 #include <isc/region.h>
