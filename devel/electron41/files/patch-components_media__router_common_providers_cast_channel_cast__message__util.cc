--- components/media_router/common/providers/cast/channel/cast_message_util.cc.orig	2026-03-13 16:54:03 UTC
+++ components/media_router/common/providers/cast/channel/cast_message_util.cc
@@ -167,7 +167,7 @@ int GetVirtualConnectPlatformValue() {
   return 4;
 #elif BUILDFLAG(IS_CHROMEOS)
   return 5;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return 6;
 #else
   return 0;
