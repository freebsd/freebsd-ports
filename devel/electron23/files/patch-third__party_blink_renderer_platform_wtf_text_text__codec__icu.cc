--- third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc.orig	2023-02-01 18:43:26 UTC
+++ third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc
@@ -116,6 +116,10 @@ void TextCodecICU::RegisterEncodingNames(EncodingNameR
       continue;
     }
 #endif
+    // Avoid codecs supported by `TextCodecCJK`.
+    if (is_text_codec_cjk_enabled && TextCodecCJK::IsSupported(standard_name)) {
+      continue;
+    }
 
 // A number of these aliases are handled in Chrome's copy of ICU, but
 // Chromium can be compiled with the system ICU.
@@ -144,12 +148,13 @@ void TextCodecICU::RegisterEncodingNames(EncodingNameR
     }
 #endif
 
-    if (is_text_codec_cjk_enabled && TextCodecCJK::IsSupported(standard_name)) {
-      continue;
+    // Avoid registering codecs registered by
+    // `TextCodecCJK::RegisterEncodingNames`.
+    if (!is_text_codec_cjk_enabled ||
+        !TextCodecCJK::IsSupported(standard_name)) {
+      registrar(standard_name, standard_name);
     }
 
-    registrar(standard_name, standard_name);
-
     uint16_t num_aliases = ucnv_countAliases(name, &error);
     DCHECK(U_SUCCESS(error));
     if (U_SUCCESS(error))
@@ -289,6 +294,7 @@ void TextCodecICU::RegisterCodecs(TextCodecRegistrar r
       continue;
     }
 #endif
+    // Avoid codecs supported by `TextCodecCJK`.
     if (is_text_codec_cjk_enabled && TextCodecCJK::IsSupported(standard_name)) {
       continue;
     }
