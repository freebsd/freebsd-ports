--- src/phonenumbers/base/thread_checker.h.orig	2020-01-18 23:13:13 UTC
+++ src/phonenumbers/base/thread_checker.h
@@ -22,7 +22,7 @@
 // Note that I18N_PHONENUMBERS_NO_THREAD_SAFETY must be defined only to let the
 // user of the library know that it can't be used in a thread-safe manner when
 // it is not depending on Boost.
-#if !defined(__linux__) && !defined(__APPLE__) && \
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && \
     !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY)
 #error Building without Boost, please provide \
        -DI18N_PHONENUMBERS_NO_THREAD_SAFETY
@@ -31,7 +31,7 @@
 #endif
 
 #if !defined(NDEBUG) && !defined(I18N_PHONENUMBERS_USE_BOOST) && \
-    (defined(__linux__) || defined(__apple__))
+    (defined(__linux__) || defined(__apple__) || defined(__FreeBSD__))
 
 #include <pthread.h>
 
