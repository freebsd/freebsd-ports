--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2025-03-24 20:50:14 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -180,7 +180,7 @@ struct BLINK_COMMON_EXPORT
     return data.send_subresource_notification;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
