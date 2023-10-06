--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h.orig	2022-09-24 10:57:32 UTC
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/thread_checker.h
@@ -22,7 +22,7 @@
 // Note that I18N_PHONENUMBERS_NO_THREAD_SAFETY must be defined only to let the
 // user of the library know that it can't be used in a thread-safe manner when
 // it is not depending on Boost.
-#if !defined(__linux__) && !defined(__APPLE__) && !defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD) && \
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD) && \
     !defined(I18N_PHONENUMBERS_NO_THREAD_SAFETY) && \
 	!((__cplusplus >= 201103L) && defined(I18N_PHONENUMBERS_USE_STDMUTEX)) && \
 	!defined(WIN32)
@@ -33,7 +33,7 @@
 #endif
 
 #if !defined(NDEBUG) && !defined(I18N_PHONENUMBERS_USE_BOOST) && \
-    (defined(__linux__) || defined(__APPLE__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD))
+    (defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD))
 
 #include <pthread.h>
 
