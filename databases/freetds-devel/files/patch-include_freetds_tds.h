--- include/freetds/tds.h.orig	2015-02-02 17:40:31.253513320 +0600
+++ include/freetds/tds.h	2015-02-02 17:41:42.603514745 +0600
@@ -144,7 +144,10 @@
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
