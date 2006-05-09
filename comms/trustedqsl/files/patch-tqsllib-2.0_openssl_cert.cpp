--- tqsllib-2.0/openssl_cert.cpp.orig	Fri Mar 11 07:47:11 2005
+++ tqsllib-2.0/openssl_cert.cpp	Wed Mar 29 11:27:41 2006
@@ -1290,6 +1290,8 @@
 							attrib->set = 1;
 #elif (OPENSSL_VERSION_NUMBER & 0xfffff000) == 0x00907000
 							attrib->single = 0;
+#elif (OPENSSL_VERSION_NUMBER & 0xfffff000) == 0x00908000
+							attrib->single = 0;
 #else
 #error "Unexpected OpenSSL version; check X509_ATTRIBUTE struct compatibility"
 #endif
