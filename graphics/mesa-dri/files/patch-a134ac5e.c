commit a134ac5ee9355779e015f8d7f9fe3e2ab22cdb86
Author: Timur Kristóf <timur.kristof@gmail.com>
Date:   Tue Jan 21 16:08:21 2020 +0100

    r600: Move get_pic_param to radeon_vce.c
    
    Signed-off-by: Timur Kristóf <timur.kristof@gmail.com>
    Reviewed-by: Marek Olšák <marek.olsak@amd.com>
    Part-of: <https://gitlab.freedesktop.org/mesa/mesa/merge_requests/3488>

diff --git src/gallium/drivers/r600/radeon_vce.c src/gallium/drivers/r600/radeon_vce.c
index 4051d73533d..16f48c69456 100644
--- src/gallium/drivers/r600/radeon_vce.c
+++ src/gallium/drivers/r600/radeon_vce.c
@@ -54,6 +54,10 @@
 #define FW_52_8_3 ((52 << 24) | (8 << 16) | (3 << 8))
 #define FW_53 (53 << 24)
 
+/* version specific function for getting parameters */
+static void (*get_pic_param)(struct rvce_encoder *enc,
+                             struct pipe_h264_enc_picture_desc *pic) = NULL;
+
 /**
  * flush commands to the hardware
  */
diff --git src/gallium/drivers/r600/radeon_vce.h src/gallium/drivers/r600/radeon_vce.h
index 71f028721b4..c5e05477763 100644
--- src/gallium/drivers/r600/radeon_vce.h
+++ src/gallium/drivers/r600/radeon_vce.h
@@ -443,10 +443,6 @@ void radeon_vce_50_init(struct rvce_encoder *enc);
 /* init vce fw 52 specific callbacks */
 void radeon_vce_52_init(struct rvce_encoder *enc);
 
-/* version specific function for getting parameters */
-void (*get_pic_param)(struct rvce_encoder *enc,
-                      struct pipe_h264_enc_picture_desc *pic);
-
 /* get parameters for vce 40.2.2 */
 void radeon_vce_40_2_2_get_param(struct rvce_encoder *enc,
                                  struct pipe_h264_enc_picture_desc *pic);
