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
