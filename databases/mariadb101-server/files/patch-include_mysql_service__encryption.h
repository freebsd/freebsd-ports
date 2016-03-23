Fix build error

--- include/mysql/service_encryption.h.orig	2015-10-15 15:43:37 UTC
+++ include/mysql/service_encryption.h
@@ -35,9 +35,11 @@ extern "C" {
 #define inline __inline
 #endif
 #else
+#ifndef __FreeBSD__
 #include <alloca.h>
 #endif
 #endif
+#endif
 
 /* returned from encryption_key_get_latest_version() */
 #define ENCRYPTION_KEY_VERSION_INVALID        (~(unsigned int)0)
