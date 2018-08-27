--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/IceSSL/configuration/AllTests.cpp
@@ -741,7 +741,11 @@ allTests(const CommunicatorPtr& communic
         openSSLVersion = plugin->getOpenSSLVersion();
         comm->destroy();
     }
+#  if defined(LIBRESSL_VERSION_NUMBER)
+    const string anonCiphers = "ADH";
+#  else
     const string anonCiphers = openSSLVersion >= 0x10100000L ? "ADH:@SECLEVEL=0" : "ADH";
+#  endif
 #endif
 
     IceSSL::ConnectionInfoPtr info;
@@ -2655,6 +2659,7 @@ allTests(const CommunicatorPtr& communic
     // This is fixed in 10.11.3
     if(!elCapitanUpdate2OrLower)
     {
+#if !defined(LIBRESSL_VERSION_NUMBER)
         //
         // This should fail because we disabled all anonymous ciphers and the server doesn't
         // provide a certificate.
@@ -2692,6 +2697,7 @@ allTests(const CommunicatorPtr& communic
         }
         fact->destroyServer(server);
         comm->destroy();
+#endif
     }
 #    ifdef ICE_USE_SECURE_TRANSPORT
     {
@@ -2843,7 +2849,7 @@ allTests(const CommunicatorPtr& communic
     //
     // No DSA support in Secure Transport / AIX 7.1
     //
-#  if !defined(ICE_USE_SECURE_TRANSPORT) && !defined(_AIX) && !defined(ICE_USE_SCHANNEL)
+#  if !defined(ICE_USE_SECURE_TRANSPORT) && !defined(_AIX) && !defined(ICE_USE_SCHANNEL) && !defined(LIBRESSL_VERSION_NUMBER)
     {
         //
         // DSA PEM keys are not supported with SChannel. Since Windows 10
@@ -4165,6 +4171,7 @@ allTests(const CommunicatorPtr& communic
 #endif
     }
 
+#if 0
 #if !defined(_AIX) && !defined(ICE_OS_UWP) && !(defined(_WIN32) && defined(ICE_USE_OPENSSL))
     //
     // On AIX 6.1, the default root certificates don't validate demo.zeroc.com.
@@ -4279,5 +4286,6 @@ allTests(const CommunicatorPtr& communic
     }
     cout << "ok" << endl;
 #endif
+#endif
     return factory;
 }
