--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h.orig	2019-12-12 12:44:12 UTC
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h
@@ -23,6 +23,7 @@
 // user of the library know that it can't be used in a thread-safe manner when
 // it is not depending on Boost.
 #if !defined(__linux__) && !defined(__APPLE__) && \
+    !defined(__FreeBSD__) && !defined(__OpenBSD__) && \
     !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY)
 #error Building without Boost, please provide \
        -DI18N_PHONENUMBERS_NO_THREAD_SAFETY
@@ -31,7 +32,7 @@
 #endif
 
 #if !defined(NDEBUG) && !defined(I18N_PHONENUMBERS_USE_BOOST) && \
-    (defined(__linux__) || defined(__apple__))
+    (defined(__linux__) || defined(__apple__)) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
 #include <pthread.h>
 
