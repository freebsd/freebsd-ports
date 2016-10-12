--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2016-10-05 16:59:08.000000000 +0200
+++ cpp/test/IceSSL/configuration/AllTests.cpp	2016-10-12 01:57:47.897380902 +0200
@@ -27,7 +27,7 @@
 //
 // With OpenSSL 1.1.0 we need to set SECLEVEL=0 to allow ADH ciphers
 //
-#  if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#  if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 const string anonCiphers = "ADH:@SECLEVEL=0";
 #  else
 const string anonCiphers = "ADH";
@@ -3215,9 +3215,7 @@
 #endif
     }
 
-#ifndef _AIX
-    // On AIX 6.1, the default root certificates don't validate demo.zeroc.com
-
+#if 0 // we don't want to talk to zeroc while building
     cout << "testing system CAs... " << flush;
     {
         InitializationData initData;
