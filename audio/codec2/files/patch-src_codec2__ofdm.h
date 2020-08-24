--- src/codec2_ofdm.h.orig	2018-05-24 01:33:34 UTC
+++ src/codec2_ofdm.h
@@ -49,9 +49,10 @@ extern "C" {
 #define OFDM_SYNC_MANUAL 2                 /* fall out of sync only under operator control */
     
 struct OFDM;
+struct OFDM_CONFIG;
 
 /* Default configuration for '700D' mode */
-const struct OFDM_CONFIG * OFDM_CONFIG_700D;
+//const struct OFDM_CONFIG * OFDM_CONFIG_700D;
 
 /* create and destroy modem states */
 
