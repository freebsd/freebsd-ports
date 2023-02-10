--- third_party/webrtc/rtc_base/network.cc.orig	2022-11-30 08:12:58 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -286,7 +286,12 @@ AdapterType GetAdapterTypeFromName(absl::string_view n
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
