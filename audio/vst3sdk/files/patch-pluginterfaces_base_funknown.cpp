--- pluginterfaces/base/funknown.cpp.orig	2021-12-16 12:29:35 UTC
+++ pluginterfaces/base/funknown.cpp
@@ -49,14 +49,15 @@
 #if defined (__ANDROID__) || defined(_LIBCPP_VERSION)
 #define SMTG_USE_STDATOMIC_H 1
 #else
-#include <ext/atomicity.h>
+//#include <ext/atomicity.h>
 #endif
 #endif // !defined (SMTG_USE_STDATOMIC_H)
 #include <stdlib.h>
 #endif
 
 #if defined (SMTG_USE_STDATOMIC_H) && SMTG_USE_STDATOMIC_H 
-#include <stdatomic.h>
+//#include <stdatomic.h>
+#include <atomic>
 #endif
 
 namespace Steinberg {
@@ -88,7 +89,7 @@ namespace FUnknownPrivate {
 int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 {
 #if SMTG_USE_STDATOMIC_H
-	return atomic_fetch_add (reinterpret_cast<atomic_int_least32_t*> (&var), d) + d;
+	return atomic_fetch_add (reinterpret_cast<std::atomic_int_least32_t*> (&var), d) + d;
 #else
 #if SMTG_OS_WINDOWS
 #ifdef __MINGW32__
@@ -100,7 +101,7 @@ int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 	return OSAtomicAdd32Barrier (d, (int32_t*)&var);
 #elif defined(__ANDROID__)
 	return atomic_fetch_add ((atomic_int*)&var, d) + d;
-#elif SMTG_OS_LINUX
+#elif SMTG_OS_LINUX && !defined(__FreeBSD__)
 	__gnu_cxx::__atomic_add (&var, d);
 	return var;
 #else
