--- 3rdparty/bx/include/bx/thread.h.orig	2015-09-30 06:29:01 UTC
+++ 3rdparty/bx/include/bx/thread.h
@@ -14,6 +14,10 @@ using namespace Windows::Foundation;
 using namespace Windows::System::Threading;
 #endif
 
+#if BX_PLATFORM_FREEBSD
+#	include <pthread_np.h>
+#endif
+
 #include "sem.h"
 
 #if BX_CONFIG_SUPPORTS_THREADING
@@ -149,8 +153,10 @@ namespace bx
 		{
 #if BX_PLATFORM_OSX || BX_PLATFORM_IOS
 			pthread_setname_np(_name);
-#elif BX_PLATFORM_LINUX || BX_PLATFORM_FREEBSD
+#elif BX_PLATFORM_LINUX
 			pthread_setname_np(m_handle, _name);
+#elif BX_PLATFORM_FREEBSD
+			pthread_set_name_np(m_handle, _name);
 #elif BX_PLATFORM_WINDOWS && BX_COMPILER_MSVC
 #	pragma pack(push, 8)
 			struct ThreadName
