--- cpp/src/IceGrid/RegistryI.cpp.orig	2013-10-04 17:48:14.000000000 +0200
+++ cpp/src/IceGrid/RegistryI.cpp	2015-02-27 18:59:30.002347000 +0100
@@ -41,6 +41,7 @@
 #include <fstream>
 
 #include <openssl/des.h> // For crypt() passwords
+#include <openssl/opensslv.h>
 
 #include <sys/types.h>
 
