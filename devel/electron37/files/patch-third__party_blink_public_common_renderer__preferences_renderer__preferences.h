--- third_party/blink/public/common/renderer_preferences/renderer_preferences.h.orig	2025-03-24 20:50:14 UTC
+++ third_party/blink/public/common/renderer_preferences/renderer_preferences.h
@@ -65,7 +65,7 @@ struct BLINK_COMMON_EXPORT RendererPreferences {
   UserAgentOverride user_agent_override;
   std::string accept_languages;
   bool send_subresource_notification{false};
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::string system_font_family_name;
 #endif
 #if BUILDFLAG(IS_WIN)
