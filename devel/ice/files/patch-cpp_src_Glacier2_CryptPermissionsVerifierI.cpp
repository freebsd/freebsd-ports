--- cpp/src/Glacier2/CryptPermissionsVerifierI.cpp.orig	2013-10-04 17:48:14.000000000 +0200
+++ cpp/src/Glacier2/CryptPermissionsVerifierI.cpp	2015-02-27 10:13:28.605561279 +0100
@@ -9,6 +9,7 @@
 
 #include <Glacier2/CryptPermissionsVerifierI.h>
 #include <openssl/des.h>
+#include <openssl/opensslv.h>
 
 using namespace std;
 using namespace Ice;
