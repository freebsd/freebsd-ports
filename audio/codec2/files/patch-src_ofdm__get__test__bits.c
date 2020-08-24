--- src/ofdm_get_test_bits.c.orig	2020-08-24 17:10:37 UTC
+++ src/ofdm_get_test_bits.c
@@ -36,6 +36,8 @@
 #include "ofdm_internal.h"
 #include "test_bits_ofdm.h"
 
+extern const struct OFDM_CONFIG * OFDM_CONFIG_700D;
+
 int main(int argc, char *argv[])
 {
     struct OFDM  *ofdm;
