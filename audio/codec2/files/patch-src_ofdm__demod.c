--- src/ofdm_demod.c.orig	2020-08-24 16:51:44 UTC
+++ src/ofdm_demod.c
@@ -49,6 +49,8 @@
 #define NFRAMES  100               /* just log the first 100 frames          */
 #define NDISCARD 20                /* BER2measure disctrds first 20 frames   */
 
+const struct OFDM_CONFIG * OFDM_CONFIG_700D;
+
 extern int payload_data_bits[];
 extern int test_bits_ofdm[];
                
