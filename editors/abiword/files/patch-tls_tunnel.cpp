--- plugins/collab/backends/service/xp/tls_tunnel.cpp-orig	2014-07-27 14:22:00.000000000 +0200
+++ plugins/collab/backends/service/xp/tls_tunnel.cpp	2014-07-27 14:22:46.000000000 +0200
@@ -124,10 +124,14 @@
 }
 
 static struct gcry_thread_cbs gcry_threads_tunnel =
+#if GCRYPT_VERSION_NUMBER < 0x010600
 { GCRY_THREAD_OPTION_USER, NULL,
   gcry_tunnel_mutex_init, gcry_tunnel_mutex_destroy,
   gcry_tunnel_mutex_lock, gcry_tunnel_mutex_unlock,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
+#else
+{ GCRY_THREAD_OPTION_USER };
+#endif
 
 bool Proxy::tls_tunnel_init() {
 	if (gcry_control(GCRYCTL_SET_THREAD_CBS, &tls_tunnel::gcry_threads_tunnel) != 0)
