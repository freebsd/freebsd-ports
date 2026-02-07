--- src/qth-data.h.orig	2017-12-29 10:28:07 UTC
+++ src/qth-data.h
@@ -30,7 +30,7 @@ typedef struct {
     gint            alt;        /*!< Altitude above sea level in meters. */
 } qth_small_t;
 
-enum {
+static enum {
     QTH_STATIC_TYPE = 0,
     QTH_GPSD_TYPE
 } qth_data_type;
