--- cpp/src/IceSSL/OpenSSLEngine.cpp.orig	2015-09-14 23:12:17.842563990 +0000
+++ cpp/src/IceSSL/OpenSSLEngine.cpp	2015-09-14 23:13:21.929560990 +0000
@@ -267,7 +267,9 @@
             string entropyDaemon = properties->getProperty("IceSSL.EntropyDaemon");
             if(!entropyDaemon.empty())
             {
+#    ifndef OPENSSL_NO_EGD
                 if(RAND_egd(entropyDaemon.c_str()) <= 0)
+#    endif
                 {
                     throw PluginInitializationException(__FILE__, __LINE__,
                                                         "IceSSL: EGD failure using file " + entropyDaemon);
