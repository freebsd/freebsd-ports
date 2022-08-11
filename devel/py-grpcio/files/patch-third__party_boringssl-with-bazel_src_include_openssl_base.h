--- third_party/boringssl-with-bazel/src/include/openssl/base.h.orig	2022-05-03 21:27:37 UTC
+++ third_party/boringssl-with-bazel/src/include/openssl/base.h
@@ -483,9 +483,6 @@ typedef void *OPENSSL_BLOCK;
 // MSVC doesn't set __cplusplus to 201103 to indicate C++11 support (see
 // https://connect.microsoft.com/VisualStudio/feedback/details/763051/a-value-of-predefined-macro-cplusplus-is-still-199711l)
 // so MSVC is just assumed to support C++11.
-#if !defined(BORINGSSL_NO_CXX) && __cplusplus < 201103L && !defined(_MSC_VER)
-#define BORINGSSL_NO_CXX
-#endif
 
 #if !defined(BORINGSSL_NO_CXX)
 
