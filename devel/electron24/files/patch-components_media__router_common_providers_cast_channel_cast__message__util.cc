--- components/media_router/common/providers/cast/channel/cast_message_util.cc.orig	2022-11-30 08:12:58 UTC
+++ components/media_router/common/providers/cast/channel/cast_message_util.cc
@@ -170,7 +170,7 @@ int GetVirtualConnectPlatformValue() {
   return 4;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return 5;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return 6;
 #else
   return 0;
