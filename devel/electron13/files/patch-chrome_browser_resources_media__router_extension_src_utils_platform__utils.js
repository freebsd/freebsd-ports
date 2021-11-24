--- chrome/browser/resources/media_router/extension/src/utils/platform_utils.js.orig	2021-07-15 19:15:42 UTC
+++ chrome/browser/resources/media_router/extension/src/utils/platform_utils.js
@@ -58,5 +58,8 @@ mr.PlatformUtils.getCurrentOS = function() {
   if (userAgent.includes('Linux')) {
     return mr.PlatformUtils.OS.LINUX;
   }
+  if (userAgent.includes('FreeBSD')) {
+    return mr.PlatformUtils.OS.LINUX;
+  }
   return mr.PlatformUtils.OS.OTHER;
 };
