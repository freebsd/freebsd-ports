libheif/plugins/encoder_svt.cc:654:34: error: assigning to 'EbColorPrimaries' from incompatible type 'uint8_t' (aka 'unsigned char')
    svt_config.color_primaries = static_cast<uint8_t>(nclx->color_primaries);
                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
libheif/plugins/encoder_svt.cc:655:43: error: assigning to 'EbTransferCharacteristics' from incompatible type 'uint8_t' (aka 'unsigned char')
    svt_config.transfer_characteristics = static_cast<uint8_t>(nclx->transfer_characteristics);
                                          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
libheif/plugins/encoder_svt.cc:656:38: error: assigning to 'EbMatrixCoefficients' from incompatible type 'uint8_t' (aka 'unsigned char')
    svt_config.matrix_coefficients = static_cast<uint8_t>(nclx->matrix_coefficients);
                                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
libheif/plugins/encoder_svt.cc:657:30: error: assigning to 'EbColorRange' from incompatible type 'int'
    svt_config.color_range = nclx->full_range_flag ? 1 : 0;
                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- libheif/plugins/encoder_svt.cc.orig	2023-12-20 10:31:30 UTC
+++ libheif/plugins/encoder_svt.cc
@@ -645,7 +645,7 @@ struct heif_error svt_encode_image(void* encoder_raw, 
 
   if (nclx) {
     svt_config.color_description_present_flag = true;
-#if SVT_AV1_VERSION_MAJOR == 1
+#if SVT_AV1_VERSION_MAJOR >= 1
     svt_config.color_primaries = static_cast<EbColorPrimaries>(nclx->color_primaries);
     svt_config.transfer_characteristics = static_cast<EbTransferCharacteristics>(nclx->transfer_characteristics);
     svt_config.matrix_coefficients = static_cast<EbMatrixCoefficients>(nclx->matrix_coefficients);
