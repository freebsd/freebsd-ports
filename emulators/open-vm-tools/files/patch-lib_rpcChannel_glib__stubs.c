--- lib/rpcChannel/glib_stubs.c.orig	2026-06-15 19:56:15 UTC
+++ lib/rpcChannel/glib_stubs.c
@@ -35,6 +35,7 @@ void *g_malloc0_n(size_t n, size_t s) { return Util_Sa
 
 void *g_malloc0(size_t s) { return Util_SafeCalloc(1, s); }
 void *g_malloc0_n(size_t n, size_t s) { return Util_SafeCalloc(n, s); }
+#undef g_free
 void g_free(void *p) { free(p); }
 
 void g_mutex_init(GMutex *mutex) { }
