--- src/ipc_actor.cpp.orig	2025-02-26 17:30:26 UTC
+++ src/ipc_actor.cpp
@@ -50,6 +50,10 @@
 # endif // !defined(EMILUA_STATIC_BUILD)
 #endif // BOOST_OS_BSD_FREE
 
+#if EMILUA_CONFIG_HAVE_RTLD_SET_VAR
+#include <link.h>
+#endif
+
 #define EMILUA_LUA_HOOK_BUFFER_SIZE (1024 * 1024)
 static_assert(EMILUA_LUA_HOOK_BUFFER_SIZE % alignof(std::max_align_t) == 0);
 
