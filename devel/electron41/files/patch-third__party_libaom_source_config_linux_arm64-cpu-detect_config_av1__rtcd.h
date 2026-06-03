--- third_party/libaom/source/config/linux/arm64-cpu-detect/config/av1_rtcd.h.orig	2026-03-20 23:30:17 UTC
+++ third_party/libaom/source/config/linux/arm64-cpu-detect/config/av1_rtcd.h
@@ -198,8 +198,10 @@ void av1_dist_wtd_convolve_y_neon(const uint8_t *src, 
 
 void av1_dist_wtd_convolve_y_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 void av1_dist_wtd_convolve_y_neon(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
+#if (VERSION_PACKED > 199937)
 void av1_dist_wtd_convolve_y_neon_dotprod(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 void av1_dist_wtd_convolve_y_neon_i8mm(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
+#endif
 RTCD_EXTERN void (*av1_dist_wtd_convolve_y)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 
 void av1_dr_prediction_z1_c(uint8_t *dst, ptrdiff_t stride, int bw, int bh, const uint8_t *above, const uint8_t *left, int upsample_above, int dx, int dy);
@@ -535,8 +537,10 @@ static void setup_rtcd_internal(void)
     if (flags & HAS_NEON_DOTPROD) av1_dist_wtd_convolve_x = av1_dist_wtd_convolve_x_neon_dotprod;
     if (flags & HAS_NEON_I8MM) av1_dist_wtd_convolve_x = av1_dist_wtd_convolve_x_neon_i8mm;
     av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon;
+#if (VERSION_PACKED > 199937)
     if (flags & HAS_NEON_DOTPROD) av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon_dotprod;
     if (flags & HAS_NEON_I8MM) av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon_i8mm;
+#endif
     av1_filter_intra_predictor = av1_filter_intra_predictor_neon;
     if (flags & HAS_NEON_I8MM) av1_filter_intra_predictor = av1_filter_intra_predictor_neon_i8mm;
     av1_get_crc32c_value = av1_get_crc32c_value_c;
