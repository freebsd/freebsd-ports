--- src/ofdm_mod.c.orig	2020-08-24 17:09:09 UTC
+++ src/ofdm_mod.c
@@ -41,6 +41,7 @@
 
 extern int payload_data_bits[];
 extern int test_bits_ofdm[];
+extern const struct OFDM_CONFIG * OFDM_CONFIG_700D;
 
 int opt_exists(char *argv[], int argc, char opt[]) {
     int i;
