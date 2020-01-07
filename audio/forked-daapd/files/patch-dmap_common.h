--- src/dmap_common.h.orig	2016-05-06 17:50:14 UTC
+++ src/dmap_common.h
@@ -46,7 +46,7 @@ dmap_get_fields_table(int *nfields);
 
 /* From dmap_fields.gperf - keep in sync, don't alter */
 const struct dmap_field *
-dmap_find_field (register const char *str, register unsigned int len);
+dmap_find_field (register const char *str, register size_t len);
 
 
 void
