
$FreeBSD$

--- include/ao/ao.h.orig
+++ include/ao/ao.h
@@ -134,7 +134,7 @@
 
 /* driver information */
 int ao_driver_id(const char *short_name);
-int ao_default_driver_id();
+int ao_default_driver_id(void);
 ao_info *ao_driver_info(int driver_id);
 ao_info **ao_driver_info_list(int *driver_count);
 char *ao_file_extension(int driver_id);
