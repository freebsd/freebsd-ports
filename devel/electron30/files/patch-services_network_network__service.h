--- services/network/network_service.h.orig	2024-04-15 20:34:03 UTC
+++ services/network/network_service.h
@@ -229,7 +229,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
       mojo::PendingReceiver<mojom::NetworkServiceTest> receiver) override;
   void SetFirstPartySets(net::GlobalFirstPartySets sets) override;
   void SetExplicitlyAllowedPorts(const std::vector<uint16_t>& ports) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetGssapiLibraryLoadObserver(
       mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
           gssapi_library_load_observer) override;
@@ -255,7 +255,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
   std::unique_ptr<net::HttpAuthHandlerFactory> CreateHttpAuthHandlerFactory(
       NetworkContext* network_context);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This is called just before a GSSAPI library may be loaded.
   void OnBeforeGssapiLibraryLoad();
 #endif  // BUILDFLAG(IS_LINUX)
@@ -481,7 +481,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
   // leaking stale listeners between tests.
   std::unique_ptr<net::NetworkChangeNotifier> mock_network_change_notifier_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   mojo::Remote<mojom::GssapiLibraryLoadObserver> gssapi_library_load_observer_;
 #endif  // BUILDFLAG(IS_LINUX)
 
