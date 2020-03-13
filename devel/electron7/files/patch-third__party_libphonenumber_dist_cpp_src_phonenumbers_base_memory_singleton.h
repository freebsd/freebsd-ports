--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h.orig	2019-12-12 12:44:12 UTC
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h
@@ -56,7 +56,7 @@ template <class T> boost::once_flag Singleton<T>::flag
 #include "phonenumbers/base/logging.h"
 #include "phonenumbers/base/thread_checker.h"
 
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 
 namespace i18n {
 namespace phonenumbers {
