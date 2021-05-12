--- third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h.orig	2021-04-14 01:08:55 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences_mojom_traits.h
@@ -154,7 +154,7 @@ struct BLINK_COMMON_EXPORT
     return data.accept_languages;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static const std::string& system_font_family_name(
       const ::blink::RendererPreferences& data) {
     return data.system_font_family_name;
