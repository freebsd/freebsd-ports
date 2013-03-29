--- src/mongo/util/net/ssl_manager.cpp.orig	2013-03-25 17:59:54.000000000 +0100
+++ src/mongo/util/net/ssl_manager.cpp	2013-03-25 18:03:11.000000000 +0100
@@ -183,6 +183,7 @@ namespace mongo {
     }
 
     void SSLManager::_setupFIPS() {
+#ifdef OPENSSL_FIPS
         // Turn on FIPS mode if requested.
         int status = FIPS_mode_set(1);
         if (!status) {
@@ -191,6 +192,9 @@ namespace mongo {
             fassertFailed(16703);
         }
         log() << "FIPS 140-2 mode activated" << endl;
+#else
+        error() << "can't activate FIPS mode: OpenSSL not built with FIPS support" << endl;
+#endif
     }
 
     bool SSLManager::_setupPEM(const std::string& keyFile , const std::string& password) {
