--- include/freetds/tds.h.orig	2015-06-09 10:34:04 UTC
+++ include/freetds/tds.h
@@ -144,7 +144,10 @@ typedef struct
 	TDS_INT      date;	/**< date, 0 = 1900-01-01 */
 	TDS_SMALLINT offset;	/**< time offset */
 	TDS_USMALLINT time_prec:3;
-	TDS_USMALLINT _res:10;
+#pragma push_macro("_res")
+#undef _res
+        TDS_USMALLINT _res:10;
+#pragma pop_macro("_res")
 	TDS_USMALLINT has_time:1;
 	TDS_USMALLINT has_date:1;
 	TDS_USMALLINT has_offset:1;
