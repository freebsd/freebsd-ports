--- src/freedv_api.c.orig	2018-05-29 05:59:17 UTC
+++ src/freedv_api.c
@@ -36,7 +36,7 @@
 #ifdef __APPLE__
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif /* __APPLE__ */
 
 #include "fsk.h"
@@ -75,6 +75,8 @@
 #define NORM_PWR_OFDM    1.00
 
 /* OFDM payload data test frame for 700D */
+
+extern const struct OFDM_CONFIG * OFDM_CONFIG_700D;
 
 extern int payload_data_bits[];
 
