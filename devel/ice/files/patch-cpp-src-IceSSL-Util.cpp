--- cpp/src/IceSSL/Util.cpp~	2016-10-05 16:59:08.000000000 +0200
+++ cpp/src/IceSSL/Util.cpp	2016-10-12 01:55:08.517427902 +0200
@@ -110,7 +110,7 @@
 {
 
 #  ifndef OPENSSL_NO_DH
-#    if OPENSSL_VERSION_NUMBER < 0x10100000L
+#    if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 // The following arrays are predefined Diffie Hellman group parameters.
 // These are known strong primes, distributed with the OpenSSL library
@@ -338,7 +338,7 @@
 //
 // Convert a predefined parameter set into a DH value.
 //
-#    if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#    if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 static DH*
 convertDH(const unsigned char* buf, int len)
 {
@@ -428,7 +428,7 @@
     // No match found. Use one of the predefined parameter sets instead.
     //
     IceUtil::Mutex::Lock sync(*this);
-#    if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#    if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     if(keyLength >= 4096)
     {
         if(!_dh4096)
