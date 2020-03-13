--- chrome/browser/ssl/captive_portal_blocking_page.cc.orig	2019-12-12 12:39:15 UTC
+++ chrome/browser/ssl/captive_portal_blocking_page.cc
@@ -124,7 +124,7 @@ std::string CaptivePortalBlockingPage::GetWiFiSSID() c
   wifi_service->GetConnectedNetworkSSID(&ssid, &error);
   if (!error.empty())
     return std::string();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ssid = net::GetWifiSSID();
 #elif defined(OS_ANDROID)
   ssid = net::android::GetWifiSSID();
