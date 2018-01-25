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
@@ -2048,7 +2048,7 @@
     //
     // No DSA support in Secure Transport / AIX 7.1 / SChannel
     //
-#if !defined(ICE_USE_SECURE_TRANSPORT) && !defined(_AIX) && !defined(ICE_USE_SCHANNEL)
+#if !defined(ICE_USE_SECURE_TRANSPORT) && !defined(_AIX) && !defined(ICE_USE_SCHANNEL)  && !defined(LIBRESSL_VERSION_NUMBER)
     {
         //
         // DSA PEM keys are not supported with SChannel. Since Windows 10
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
