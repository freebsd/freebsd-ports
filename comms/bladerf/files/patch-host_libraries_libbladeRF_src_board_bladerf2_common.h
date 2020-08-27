--- host/libraries/libbladeRF/src/board/bladerf2/common.h.orig	2020-08-27 20:37:28 UTC
+++ host/libraries/libbladeRF/src/board/bladerf2/common.h
@@ -207,7 +207,7 @@ extern const float ina219_r_shunt;
 /* Constants */
 /******************************************************************************/
 
-char const *bladerf2_state_to_string[4];
+extern char const *bladerf2_state_to_string[4];
 
 
 /******************************************************************************/
