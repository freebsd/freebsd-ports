--- components/gcm_driver/gcm_client.h.orig	2019-09-10 11:13:52 UTC
+++ components/gcm_driver/gcm_client.h
@@ -85,6 +85,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
