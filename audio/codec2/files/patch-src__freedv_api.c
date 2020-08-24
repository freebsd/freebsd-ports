--- src/freedv_api.c.orig	2020-08-24 17:11:35 UTC
+++ src/freedv_api.c
@@ -76,6 +76,8 @@
 
 /* OFDM payload data test frame for 700D */
 
+extern const struct OFDM_CONFIG * OFDM_CONFIG_700D;
+
 extern int payload_data_bits[];
 
 /*---------------------------------------------------------------------------*\
