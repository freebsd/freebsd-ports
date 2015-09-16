--- include/freetds/tds.h.orig	2015-05-21 09:00:35 UTC
+++ include/freetds/tds.h
@@ -144,7 +144,10 @@ typedef struct
 	TDS_INT      date;	/**< date, 0 = 1900-01-01 */
 	TDS_SMALLINT offset;	/**< time offset */
 	TDS_USMALLINT time_prec:3;
+#pragma push_macro("_res")
+#undef _res
 	TDS_USMALLINT _res:10;
+#pragma pop_macro("_res")
 	TDS_USMALLINT has_time:1;
 	TDS_USMALLINT has_date:1;
 	TDS_USMALLINT has_offset:1;
