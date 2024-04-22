--- net/base/mock_network_change_notifier.h.orig	2023-08-10 01:48:47 UTC
+++ net/base/mock_network_change_notifier.h
@@ -84,7 +84,7 @@ class MockNetworkChangeNotifier : public NetworkChange
   // use_default_connection_cost_implementation is set to true.
   ConnectionCost GetCurrentConnectionCost() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetAddressMapOwnerLinux(AddressMapOwnerLinux* address_map_owner) {
     address_map_owner_ = address_map_owner;
   }
@@ -104,7 +104,7 @@ class MockNetworkChangeNotifier : public NetworkChange
   bool use_default_connection_cost_implementation_ = false;
   NetworkChangeNotifier::NetworkList connected_networks_;
   std::unique_ptr<SystemDnsConfigChangeNotifier> dns_config_notifier_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   raw_ptr<AddressMapOwnerLinux> address_map_owner_ = nullptr;
 #endif
 };
