--- IMG_webp.c.orig	2012-01-21 01:51:33 UTC
+++ IMG_webp.c
@@ -47,9 +47,9 @@ static struct {
 static struct {
 	int loaded;
 	void *handle;
-	int/*VP8StatuCode*/ (*webp_get_features_internal) (const uint8_t *data, uint32_t data_size, WebPBitstreamFeatures* const features, int decoder_abi_version);
-	uint8_t*	(*webp_decode_rgb_into) (const uint8_t* data, uint32_t data_size, uint8_t* output_buffer, int output_buffer_size, int output_stride);
-	uint8_t*	(*webp_decode_rgba_into) (const uint8_t* data, uint32_t data_size, uint8_t* output_buffer, int output_buffer_size, int output_stride);
+	VP8StatusCode   (*webp_get_features_internal) (const uint8_t *data, size_t data_size, WebPBitstreamFeatures* features, int decoder_abi_version);
+	uint8_t*	(*webp_decode_rgb_into) (const uint8_t* data, size_t data_size, uint8_t* output_buffer, size_t output_buffer_size, int output_stride);
+	uint8_t*	(*webp_decode_rgba_into) (const uint8_t* data, size_t data_size, uint8_t* output_buffer, size_t output_buffer_size, int output_stride);
 } lib;
 
 #ifdef LOAD_WEBP_DYNAMIC
