--- src/axel.c.orig	2022-11-25 02:14:41 UTC
+++ src/axel.c
@@ -151,7 +151,7 @@ axel_new(conf_t *conf, int count, const search_t *res)
 			axel->conf->buffer_size = axel->conf->max_speed;
 		}
 		uint64_t delay =
-			UINT64_C(1073741824) * axel->conf->buffer_size *
+			((uint64_t)1073741824) * axel->conf->buffer_size *
 			axel->conf->num_connections / axel->conf->max_speed;
 
 		axel->delay_time.tv_sec  = delay / 1073741824;
