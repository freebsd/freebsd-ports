--- third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc.orig	2025-03-24 20:50:14 UTC
+++ third_party/blink/common/renderer_preferences/renderer_preferences_mojom_traits.cc
@@ -77,7 +77,7 @@ bool StructTraits<blink::mojom::RendererPreferencesDat
 
   out->send_subresource_notification = data.send_subresource_notification();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadSystemFontFamilyName(&out->system_font_family_name))
     return false;
 #endif
