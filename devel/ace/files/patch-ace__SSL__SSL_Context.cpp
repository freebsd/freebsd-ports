--- ace/SSL/SSL_Context.cpp.orig
+++ ace/SSL/SSL_Context.cpp
@@ -274,7 +274,7 @@
     case ACE_SSL_Context::TLSv1:
       method = ::TLSv1_method ();
       break;
-#ifdef TLS1_1_VERSION
+#if defined(TLS1_1_VERSION) && (TLS_MAX_VERSION >= TLS1_1_VERSION)
     case ACE_SSL_Context::TLSv1_1_client:
       method = ::TLSv1_1_client_method ();
       break;
@@ -285,7 +285,7 @@
       method = ::TLSv1_1_method ();
       break;
 #endif
-#ifdef TLS1_2_VERSION
+#if defined(TLS1_2_VERSION) && (TLS_MAX_VERSION >= TLS1_2_VERSION)
     case ACE_SSL_Context::TLSv1_2_client:
       method = ::TLSv1_2_client_method ();
       break;
--- ace/SSL/SSL_Context.cpp.orig	2015-02-27 13:11:14.741825000 +0100
+++ ace/SSL/SSL_Context.cpp	2015-02-27 13:13:32.038824893 +0100
@@ -556,19 +556,9 @@
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
   // OpenSSL < 0.9.5 doesn't have EGD support.
   ACE_UNUSED_ARG (socket_file);
   ACE_NOTSUP_RETURN (-1);
-#else
-  // RAND_egd() returns the amount of entropy used to seed the random
-  // number generator.  The actual value should be greater than 16,
-  // i.e. 128 bits.
-  if (::RAND_egd (socket_file) > 0)
-    return 0;
-  else
-    return -1;
-#endif  /* OPENSSL_VERSION_NUMBER >= 0x00905100L */
 }
 
 int
 
