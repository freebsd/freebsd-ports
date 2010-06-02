--- ./src/modules/extra/m_ssl_gnutls.cpp.orig	2008-04-02 14:37:17.000000000 -0400
+++ ./src/modules/extra/m_ssl_gnutls.cpp	2010-03-23 20:27:41.000000000 -0400
@@ -32,8 +32,8 @@
 #endif
 
 /* $ModDesc: Provides SSL support for clients */
-/* $CompileFlags: exec("libgnutls-config --cflags") */
-/* $LinkerFlags: rpath("libgnutls-config --libs") exec("libgnutls-config --libs") */
+/* $CompileFlags: pkgconfincludes("gnutls","/gnutls/gnutls.h","") */
+/* $LinkerFlags: rpath("pkg-config --libs gnutls") pkgconflibs("gnutls","/libgnutls.so","-lgnutls") */
 /* $ModDep: transport.h */
 
 
