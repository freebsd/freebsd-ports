--- chrome/browser/net/system_network_context_manager.h.orig	2024-02-21 00:20:34 UTC
+++ chrome/browser/net/system_network_context_manager.h
@@ -200,7 +200,7 @@ class SystemNetworkContextManager {
   class URLLoaderFactoryForSystem;
   class NetworkProcessLaunchWatcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   class GssapiLibraryLoadObserver
       : public network::mojom::GssapiLibraryLoadObserver {
    public:
@@ -236,7 +236,7 @@ class SystemNetworkContextManager {
   void UpdateExplicitlyAllowedNetworkPorts();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Applies the current value of the kEnforceLocalAnchorConstraintsEnabled
   // pref to the enforcement state.
   void UpdateEnforceLocalAnchorConstraintsEnabled();
@@ -284,7 +284,7 @@ class SystemNetworkContextManager {
 
   static std::optional<bool> certificate_transparency_enabled_for_testing_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GssapiLibraryLoadObserver gssapi_library_loader_observer_{this};
 #endif  // BUILDFLAG(IS_LINUX)
 
