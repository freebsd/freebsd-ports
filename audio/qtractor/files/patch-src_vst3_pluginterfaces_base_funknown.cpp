-- Use C++ <atomic> instead of C stdatomic.h for FreeBSD libc++ compatibility.
-- This and similar issues have been reported to VST but they aren't too responsive.

--- src/vst3/pluginterfaces/base/funknown.cpp.orig	2026-09-06 17:43:34 UTC
+++ src/vst3/pluginterfaces/base/funknown.cpp
@@ -55,7 +55,7 @@
 #endif
 
 #if defined (SMTG_USE_STDATOMIC_H) && SMTG_USE_STDATOMIC_H 
-#include <stdatomic.h>
+#include <atomic>
 #endif
 
 namespace Steinberg {
@@ -87,7 +87,7 @@ int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 {
 #if SMTG_USE_STDATOMIC_H
-	return atomic_fetch_add (reinterpret_cast<atomic_int_least32_t*> (&var), d) + d;
+	return atomic_fetch_add (reinterpret_cast<std::atomic_int_least32_t*> (&var), d) + d;
 #else
 #if SMTG_OS_WINDOWS
 #ifdef __MINGW32__
