--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h.orig	2022-09-24 10:57:32 UTC
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h
@@ -22,7 +22,7 @@
 #elif (__cplusplus >= 201103L) && defined(I18N_PHONENUMBERS_USE_STDMUTEX)
 // C++11 Lock implementation based on std::mutex.
 #include "phonenumbers/base/memory/singleton_stdmutex.h"
-#elif defined(__linux__) || defined(__APPLE__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(I18N_PHONENUMBERS_HAVE_POSIX_THREAD)
 #include "phonenumbers/base/memory/singleton_posix.h"
 #elif defined(WIN32)
 #include "phonenumbers/base/memory/singleton_win32.h"
