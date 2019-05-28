--- components/gcm_driver/gcm_client.h.orig	2019-03-15 06:37:14 UTC
+++ components/gcm_driver/gcm_client.h
@@ -86,6 +86,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
