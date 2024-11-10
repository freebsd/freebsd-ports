--- libheif/context.cc.orig	2024-11-01 10:56:56 UTC
+++ libheif/context.cc
@@ -1154,7 +1154,7 @@ Result<std::shared_ptr<ImageItem>> HeifContext::encode
   heif_encoding_options options = in_options;
 
   if (const auto* nclx = output_image_item->get_forced_output_nclx()) {
-    options.output_nclx_profile = nclx;
+    options.output_nclx_profile = const_cast<heif_color_profile_nclx*>(nclx);
   }
 
   Result<std::shared_ptr<HeifPixelImage>> srcImageResult = output_image_item->convert_colorspace_for_encoding(pixel_image,
