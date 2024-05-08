--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2023-11-06 09:24:19 UTC
+++ cpp/test/IceSSL/configuration/AllTests.cpp
@@ -588,7 +588,11 @@ allTests(Test::TestHelper* helper, const string& /*tes
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
@@ -2528,6 +2532,7 @@ allTests(Test::TestHelper* helper, const string& /*tes
     }
 
     {
+#if !defined(LIBRESSL_VERSION_NUMBER)
         //
         // This should fail because we disabled all anonymous ciphers and the server doesn't
         // provide a certificate.
@@ -2710,6 +2715,7 @@ allTests(Test::TestHelper* helper, const string& /*tes
         }
         fact->destroyServer(server);
         comm->destroy();
+#endif
     }
 
     {
