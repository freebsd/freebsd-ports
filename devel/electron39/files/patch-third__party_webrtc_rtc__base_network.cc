--- third_party/webrtc/rtc_base/network.cc.orig	2025-08-26 20:49:50 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -303,7 +303,12 @@ AdapterType GetAdapterTypeFromName(absl::string_view n
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
