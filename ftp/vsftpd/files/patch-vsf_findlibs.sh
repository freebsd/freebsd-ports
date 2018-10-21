--- vsf_findlibs.sh.orig	2012-03-28 02:17:41 UTC
+++ vsf_findlibs.sh
@@ -69,7 +69,7 @@ locate_library /usr/shlib/librt.so && ec
 locate_library /usr/lib/libsendfile.so && echo "-lsendfile";
 
 # OpenSSL
-if find_func SSL_library_init ssl.o; then
+if find_func SSL_CTX_new ssl.o; then
   echo "-lssl -lcrypto";
 fi
 
