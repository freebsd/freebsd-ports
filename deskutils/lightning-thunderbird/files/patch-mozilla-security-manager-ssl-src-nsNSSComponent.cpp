--- mozilla/security/manager/ssl/src/nsNSSComponent.cpp.orig	Mon May 29 23:10:54 2006
+++ mozilla/security/manager/ssl/src/nsNSSComponent.cpp	Mon May 29 23:12:22 2006
@@ -110,6 +110,7 @@
 #include "nss.h"
 #include "pk11func.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "sechash.h"
