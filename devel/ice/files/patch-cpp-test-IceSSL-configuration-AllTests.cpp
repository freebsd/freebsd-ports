--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2015-06-23 15:30:20.000000000 +0000
+++ cpp/test/IceSSL/configuration/AllTests.cpp	2015-09-15 00:15:34.865304987 +0000
@@ -7,6 +7,7 @@
 //
 // **********************************************************************
 
+#include <openssl/ssl.h>
 #include <Ice/Ice.h>
 #include <IceSSL/Plugin.h>
 #include <TestCommon.h>
@@ -1292,14 +1293,22 @@
         InitializationData initData;
         initData.properties = createClientProps(defaultProps, defaultDir, defaultHost, p12, "c_rsa_ca1", "cacert1");
         initData.properties->setProperty("IceSSL.VerifyPeer", "0");
+#  ifdef SSL_TXT_TLSV1_1
+        initData.properties->setProperty("IceSSL.Protocols", "tlsv1_1");
+#  else
         initData.properties->setProperty("IceSSL.Protocols", "ssl3");
+#  endif
         CommunicatorPtr comm = initialize(initData);
 
         Test::ServerFactoryPrx fact = Test::ServerFactoryPrx::checkedCast(comm->stringToProxy(factoryRef));
         test(fact);
         Test::Properties d = createServerProps(defaultProps, defaultDir, defaultHost, p12, "s_rsa_ca1", "cacert1");
         d["IceSSL.VerifyPeer"] = "0";
+#  ifdef SSL_TXT_TLSV1_1
+        d["IceSSL.Protocols"] = "tlsv1_0";
+#  else
         d["IceSSL.Protocols"] = "tls";
+#  endif
         Test::ServerPrx server = fact->createServer(d);
         try
         {
@@ -1329,7 +1340,11 @@
         test(fact);
         d = createServerProps(defaultProps, defaultDir, defaultHost, p12, "s_rsa_ca1", "cacert1");
         d["IceSSL.VerifyPeer"] = "0";
+#  ifdef SSL_TXT_TLSV1_1
+        d["IceSSL.Protocols"] = "tlsv1_1, tlsv1_0";
+#  else
         d["IceSSL.Protocols"] = "tls, ssl3";
+#  endif
         server = fact->createServer(d);
         try
         {
@@ -1351,6 +1362,7 @@
             InitializationData initData;
             initData.properties = createClientProps(defaultProps, defaultDir, defaultHost, p12, "c_rsa_ca1", "cacert1");
             initData.properties->setProperty("IceSSL.VerifyPeer", "0");
+            // on modern openssl this simply fails as ssl3 is not supported by the client
             initData.properties->setProperty("IceSSL.Protocols", "ssl3");
             CommunicatorPtr comm = initialize(initData);
 
@@ -1386,14 +1398,22 @@
         {
             InitializationData initData;
             initData.properties = createClientProps(defaultProps, defaultDir, defaultHost, p12, "", "cacert1");
+#  ifdef SSL_TXT_TLSV1_1
+            initData.properties->setProperty("IceSSL.Protocols", "tlsv1_1");
+#  else
             initData.properties->setProperty("IceSSL.Protocols", "ssl3");
+#  endif
             CommunicatorPtr comm = initialize(initData);
 
             Test::ServerFactoryPrx fact = Test::ServerFactoryPrx::checkedCast(comm->stringToProxy(factoryRef));
             test(fact);
             Test::Properties d = createServerProps(defaultProps, defaultDir, defaultHost, p12, "s_rsa_ca1", "");
             d["IceSSL.VerifyPeer"] = "0";
+#  ifdef SSL_TXT_TLSV1_1
+            d["IceSSL.Protocols"] = "tls, tls1_1, tls1_2";
+#  else
             d["IceSSL.Protocols"] = "ssl3, tls, tls1_1, tls1_2";
+#  endif
             Test::ServerPrx server = fact->createServer(d);
             try
             {
@@ -3164,6 +3184,7 @@
 #endif
     }
 
+#if 0 // we don't want to talk to zeroc while building
     cout << "testing system CAs... " << flush;
     {
         InitializationData initData;
@@ -3208,6 +3229,7 @@
         comm->destroy();
     }
     cout << "ok" << endl;
+#endif
 
     if(shutdown)
     {
