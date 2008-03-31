--- libiqxmlrpc/utf_conv.cc.orig	2007-04-07 00:27:29.000000000 +0700
+++ libiqxmlrpc/utf_conv.cc	2008-04-01 03:27:31.000000000 +0700
@@ -89,7 +89,7 @@
   size_t ileft = ilen;
   size_t oleft = olen;
 
-#if defined (_WINDOWS) || defined (__CYGWIN__)
+#if defined(_LIBICONV_VERSION)
   const char* ibuf = s.c_str();
 #else
   char* ibuf = const_cast<char*>(s.c_str());
