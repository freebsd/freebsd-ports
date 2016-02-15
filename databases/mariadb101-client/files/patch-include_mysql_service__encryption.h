--- include/mysql/service_encryption.h.orig	2015-12-23 15:33:29 UTC
+++ include/mysql/service_encryption.h
@@ -37,9 +37,11 @@ extern "C" {
 #elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <stdlib.h>
 #else
+#ifndef __FreeBSD__
 #include <alloca.h>
 #endif
 #endif
+#endif
 
 /* returned from encryption_key_get_latest_version() */
 #define ENCRYPTION_KEY_VERSION_INVALID        (~(unsigned int)0)
