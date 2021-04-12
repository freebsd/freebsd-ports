--- test/vfs/redirect-rejected-names-cgi-http-to-https.cpp.orig	2017-07-14 21:55:36 UTC
+++ test/vfs/redirect-rejected-names-cgi-http-to-https.cpp
@@ -148,7 +148,7 @@ struct Test : protected ncbi :: NK :: Sh
 
 TEST_CASE(TEST) {
 
-#define RESOLVER_CGI_HEAD "test.ncbi.nlm.nih."
+#define RESOLVER_CGI_HEAD "www.ncbi.nlm.nih."
 
 #ifdef VDB_3162
 #else
