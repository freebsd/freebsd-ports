--- pluginterfaces/base/funknown.cpp.orig	2021-03-22 20:19:14 UTC
+++ pluginterfaces/base/funknown.cpp
@@ -50,7 +50,7 @@
 #ifdef __ANDROID__
 #include <stdatomic.h>
 #else
-#include <ext/atomicity.h>
+//#include <ext/atomicity.h>
 #endif
 #include <stdlib.h>
 #endif
@@ -97,7 +97,7 @@ int32 PLUGIN_API atomicAdd (int32& var, int32 d)
 #endif
 #elif defined(__ANDROID__)
 	return atomic_fetch_add ((atomic_int*)&var, d) + d;
-#elif SMTG_OS_LINUX
+#elif SMTG_OS_LINUX && !defined(__FreeBSD__)
 	__gnu_cxx::__atomic_add (&var, d);
 	return var;
 #else
