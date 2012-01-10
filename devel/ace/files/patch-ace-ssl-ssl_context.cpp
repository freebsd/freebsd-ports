--- ace/SSL/SSL_Context.cpp.orig	2012-01-10 18:04:45.000000000 +0100
+++ ace/SSL/SSL_Context.cpp	2012-01-10 18:17:42.000000000 +0100
@@ -231,7 +231,11 @@
   if (this->context_ != 0)
     return -1;
 
+#if OPENSSL_VERSION_NUMBER < 0x1000000f
   SSL_METHOD *method = 0;
+#else
+  const SSL_METHOD *method = 0;
+#endif
 
   switch (mode)
     {
