--- ppapi/proxy/flash_resource.cc.orig	2019-12-12 12:39:54 UTC
+++ ppapi/proxy/flash_resource.cc
@@ -136,7 +136,7 @@ double FlashResource::GetLocalTimeZoneOffset(PP_Instan
   // require filesystem access prohibited by the sandbox.
   // TODO(shess): Figure out why OSX needs the access, the sandbox warmup should
   // handle it.  http://crbug.com/149006
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   int32_t result = SyncCall<PpapiPluginMsg_Flash_GetLocalTimeZoneOffsetReply>(
       BROWSER,
       PpapiHostMsg_Flash_GetLocalTimeZoneOffset(PPTimeToTime(t)),
