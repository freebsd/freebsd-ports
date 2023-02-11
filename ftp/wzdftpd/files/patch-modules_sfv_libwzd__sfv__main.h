--- modules/sfv/libwzd_sfv_main.h.orig	2006-05-29 16:45:55 UTC
+++ modules/sfv/libwzd_sfv_main.h
@@ -15,7 +15,7 @@ typedef struct {
   double size_total;
 } wzd_release_stats;
 
-wzd_sfv_config SfvConfig; /*Our main SFV config */
+extern wzd_sfv_config SfvConfig; /*Our main SFV config */
 char * create_filepath(const char *dir, const char * file);
 
 
