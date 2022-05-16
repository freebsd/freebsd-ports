--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h.orig	2022-05-11 07:04:37 UTC
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h
@@ -23,7 +23,8 @@
 // user of the library know that it can't be used in a thread-safe manner when
 // it is not depending on Boost.
 #if !defined(__linux__) && !defined(__APPLE__) && \
-    !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY)
+    !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY) && !defined(__OpenBSD__) && \
+    !defined(__FreeBSD__)
 #error Building without Boost, please provide \
        -DI18N_PHONENUMBERS_NO_THREAD_SAFETY
 #endif
@@ -31,7 +32,8 @@
 #endif
 
 #if !defined(NDEBUG) && !defined(I18N_PHONENUMBERS_USE_BOOST) && \
-    (defined(__linux__) || defined(__apple__))
+    (defined(__linux__) || defined(__apple__) || defined(__OpenBSD__) || \
+     defined(__FreeBSD__))
 
 #include <pthread.h>
 
