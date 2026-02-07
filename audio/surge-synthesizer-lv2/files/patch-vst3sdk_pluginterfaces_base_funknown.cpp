--- vst3sdk/pluginterfaces/base/funknown.cpp.orig	2020-04-15 17:56:07 UTC
+++ vst3sdk/pluginterfaces/base/funknown.cpp
@@ -36,8 +36,13 @@
 #endif
 
 #if SMTG_OS_LINUX
-#include <ext/atomicity.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+# include <sys/types.h>
+# include <machine/atomic.h>
+#else
+# include <ext/atomicity.h>
 #endif
+#endif
 
 namespace Steinberg {
 
@@ -72,7 +77,11 @@ int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 #elif SMTG_OS_MACOS
 	return OSAtomicAdd32Barrier (d, (int32_t*)&var);
 #elif SMTG_OS_LINUX
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+	(*(u_int *)(&var) += (d));
+#else
 	__gnu_cxx::__atomic_add (&var, d);
+#endif
 	return var;
 #else
 #warning implement me!
