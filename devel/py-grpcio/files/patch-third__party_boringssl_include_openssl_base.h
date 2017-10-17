--- third_party/boringssl/include/openssl/base.h.orig	2017-09-27 21:43:59 UTC
+++ third_party/boringssl/include/openssl/base.h
@@ -328,9 +328,6 @@ typedef void *OPENSSL_BLOCK;
 // MSVC doesn't set __cplusplus to 201103 to indicate C++11 support (see
 // https://connect.microsoft.com/VisualStudio/feedback/details/763051/a-value-of-predefined-macro-cplusplus-is-still-199711l)
 // so MSVC is just assumed to support C++11.
-#if !defined(BORINGSSL_NO_CXX) && __cplusplus < 201103L && !defined(_MSC_VER)
-#define BORINGSSL_NO_CXX
-#endif
 
 #if !defined(BORINGSSL_NO_CXX)
 extern "C++" {
