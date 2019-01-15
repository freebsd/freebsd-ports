--- libgdmaps/gdgeoip2.c.orig	2019-01-15 00:17:32 UTC
+++ libgdmaps/gdgeoip2.c
@@ -172,12 +172,7 @@ static geoip2_t* geoip2_new(const char* 
     db->is_city = !!strstr(meta->database_type, "City");
 
     if(db->is_city) {
-        // 1546300799 == 2018-12-31T23:59:59
-        if(city_auto_mode && strstr(meta->database_type, "GeoLite2") && meta->build_epoch > (uint64_t)1546300799LLU) {
-            dmn_log_err("plugin_geoip: map '%s': GeoIP2 DB '%s' appears to be a post-2018 GeoLite2-City database, which will not work with auto_dc_coords as configured because these databases lack the latitude and longitude data present in the commercial version.  See the auto_dc_coords section of the gdnsd-plugin-geoip documentation for more details.", map_name, pathname);
-            geoip2_destroy(db);
-            return NULL;
-        }
+	// noop
     } else {
         if(city_auto_mode) {
             dmn_log_err("plugin_geoip: map '%s': GeoIP2 DB '%s' is not a City-level"
