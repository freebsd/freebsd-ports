--- third_party/blink/renderer/platform/fonts/font_custom_platform_data.cc.orig	2026-10-19 21:50:55 UTC
+++ third_party/blink/renderer/platform/fonts/font_custom_platform_data.cc
@@ -328,7 +328,8 @@ FontCustomPlatformData* FontCustomPlatformData::Create
     SharedBuffer* buffer,
     String& ots_parse_message) {
   DCHECK(buffer);
-  base::expected<DecodedWebFont, String> decode_result = DecodeWebFont(buffer);
+  base::expected<DecodedWebFont, String> decode_result =
+      DecodedWebFont::Create(buffer);
   if (!decode_result.has_value()) {
     ots_parse_message = std::move(decode_result).error();
     return nullptr;
