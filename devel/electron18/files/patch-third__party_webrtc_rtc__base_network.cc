--- third_party/webrtc/rtc_base/network.cc.orig	2022-05-19 05:18:47 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -258,7 +258,12 @@ AdapterType GetAdapterTypeFromName(const char* network
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::NetworkManager() {}
