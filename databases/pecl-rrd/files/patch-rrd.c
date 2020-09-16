--- rrd.c.orig	2020-08-28 12:06:18 UTC
+++ rrd.c
@@ -55,7 +55,7 @@ PHP_FUNCTION(rrd_fetch)
 	rrd_args *argv;
 	/* returned values if rrd_fetch doesn't fail */
 	time_t start, end;
-	ulong step,
+	u_long step,
 	ds_cnt; /* count of data sources */
 	char **ds_namv; /* list of data source names */
 	rrd_value_t *ds_data; /* all data from all sources */
@@ -396,11 +396,11 @@ PHP_FUNCTION(rrd_xport)
 	/* return values from rrd_xport */
 	int xxsize;
 	time_t start, end, time_index;
-	ulong step, outvar_count;
+	u_long step, outvar_count;
 	char **legend_v;
 	rrd_value_t *data, *data_ptr;
 	zval zv_data;
-	ulong outvar_index;
+	u_long outvar_index;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS(), "a", &zv_arr_options) == FAILURE) {
 		return;
