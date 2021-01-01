--- net/tools/quic/quic_http_proxy_backend.cc.orig	2019-09-10 11:14:11 UTC
+++ net/tools/quic/quic_http_proxy_backend.cc
@@ -160,7 +160,7 @@ void QuicHttpProxyBackend::InitializeURLRequestContext
   // Enable HTTP2, but disable QUIC on the backend
   context_builder.SetSpdyAndQuicEnabled(true /* http2 */, false /* quic */);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, use a fixed ProxyConfigService, since the default one
   // depends on glib.
   context_builder.set_proxy_config_service(
