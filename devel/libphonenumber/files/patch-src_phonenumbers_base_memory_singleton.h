--- src/phonenumbers/base/memory/singleton.h.orig	2020-01-18 23:13:06 UTC
+++ src/phonenumbers/base/memory/singleton.h
@@ -56,7 +56,7 @@ template <class T> boost::once_flag Singleton<T>::flag
 #include "phonenumbers/base/logging.h"
 #include "phonenumbers/base/thread_checker.h"
 
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 
 namespace i18n {
 namespace phonenumbers {
