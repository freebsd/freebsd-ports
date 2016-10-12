--- cpp/src/IceSSL/OpenSSLEngine.cpp.orig	2016-10-05 16:59:08.000000000 +0200
+++ cpp/src/IceSSL/OpenSSLEngine.cpp	2016-10-12 01:59:40.150375902 +0200
@@ -43,7 +43,7 @@
 int instanceCount = 0;
 bool initOpenSSL = false;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 IceUtil::Mutex* locks = 0;
 #endif
 
@@ -62,7 +62,7 @@
         // OpenSSL 1.1.0 introduces a new thread API and removes 
         // the need to use a custom thread callback.
         //
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         CRYPTO_set_locking_callback(0);
         CRYPTO_set_id_callback(0);
 
@@ -87,7 +87,7 @@
 // OpenSSL 1.1.0 introduces a new thread API and removes 
 // the need to use a custom thread callback.
 //
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 //
 // OpenSSL mutex callback.
 //
@@ -158,7 +158,7 @@
 DH*
 IceSSL_opensslDHCallback(SSL* ssl, int /*isExport*/, int keyLength)
 {
-#  if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#  if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     SSL_CTX* ctx = SSL_get_SSL_CTX(ssl);
 #  else
     SSL_CTX* ctx = ssl->ctx;
@@ -219,7 +219,7 @@
             //
             // OpenSSL 1.1.0 remove the need for library initialization and cleanup.
             //
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
             //
             // Create the mutexes and set the callbacks.
             //
@@ -292,7 +292,9 @@
             string entropyDaemon = properties->getProperty("IceSSL.EntropyDaemon");
             if(!entropyDaemon.empty())
             {
+#    ifndef OPENSSL_NO_EGD
                 if(RAND_egd(entropyDaemon.c_str()) <= 0)
+#    endif
                 {
                     throw PluginInitializationException(__FILE__, __LINE__,
                                                         "IceSSL: EGD failure using file " + entropyDaemon);
@@ -326,7 +328,7 @@
 //
 // OpenSSL 1.1.0 remove the need for library initialization and cleanup.
 //
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     //
     // Clean up OpenSSL resources.
     //
@@ -399,7 +401,7 @@
                                                     "IceSSL: unable to create SSL context:\n" + sslErrors());
             }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
             int securityLevel = properties->getPropertyAsIntWithDefault(propPrefix + "SecurityLevel", -1);
             if(securityLevel != -1)
             {
@@ -954,7 +956,7 @@
 SSL_METHOD*
 OpenSSLEngine::getMethod(int /*protocols*/)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     SSL_METHOD* meth = const_cast<SSL_METHOD*>(TLS_method());
 #else
     //
