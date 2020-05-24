--- components/gcm_driver/gcm_client.h.orig	2019-04-08 08:32:49 UTC
+++ components/gcm_driver/gcm_client.h
@@ -85,6 +85,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
