--- ./src/modules/extra/m_ssl_openssl.cpp.orig	2008-04-18 09:13:19.000000000 +0100
+++ ./src/modules/extra/m_ssl_openssl.cpp	2008-04-18 09:14:44.000000000 +0100
@@ -38,8 +38,7 @@
 #endif
 
 /* $ModDesc: Provides SSL support for clients */
-/* $CompileFlags: pkgconfversion("openssl","0.9.7") pkgconfincludes("openssl","/openssl/ssl.h","") */
-/* $LinkerFlags: rpath("pkg-config --libs openssl") pkgconflibs("openssl","/libssl.so","-lssl -lcrypto -ldl") */
+/* $LinkerFlags: -lssl -lcrypto */
 /* $ModDep: transport.h */
 
 enum issl_status { ISSL_NONE, ISSL_HANDSHAKING, ISSL_OPEN };
