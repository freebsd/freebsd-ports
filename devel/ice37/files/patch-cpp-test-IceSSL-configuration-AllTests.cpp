--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/IceSSL/configuration/AllTests.cpp
@@ -743,7 +743,11 @@ allTests(Test::TestHelper* helper, const string& /*tes
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
@@ -2681,6 +2685,7 @@ allTests(Test::TestHelper* helper, const string& /*tes
     }
 
     {
+#if !defined(LIBRESSL_VERSION_NUMBER)
         //
         // This should fail because we disabled all anonymous ciphers and the server doesn't
         // provide a certificate.
@@ -2718,6 +2723,7 @@ allTests(Test::TestHelper* helper, const string& /*tes
         }
         fact->destroyServer(server);
         comm->destroy();
+#endif
     }
 #    ifdef ICE_USE_SECURE_TRANSPORT
     {
