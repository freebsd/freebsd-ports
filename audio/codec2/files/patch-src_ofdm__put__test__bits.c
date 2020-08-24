--- src/ofdm_put_test_bits.c.orig	2020-08-24 17:20:41 UTC
+++ src/ofdm_put_test_bits.c
@@ -36,6 +36,8 @@
 #include "codec2_ofdm.h"
 #include "test_bits_ofdm.h"
 
+extern const struct OFDM_CONFIG * OFDM_CONFIG_700D;
+
 #define LOG_FRAMES 100
 #define NDISCARD   20
 
