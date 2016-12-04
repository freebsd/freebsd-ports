--- postgis/lwgeom_accum.c.orig	2014-12-01 08:47:21 UTC
+++ postgis/lwgeom_accum.c
@@ -106,7 +106,11 @@ pgis_geometry_accum_transfn(PG_FUNCTION_
 		         errmsg("could not determine input data type")));
 
 	if (fcinfo->context && IsA(fcinfo->context, AggState))
-		aggcontext = ((AggState *) fcinfo->context)->aggcontext;
+#if POSTGIS_PGSQL_VERSION >= 95
+		aggcontext = ((AggState *) fcinfo->context)->aggcontexts;
+#else
+ 		aggcontext = ((AggState *) fcinfo->context)->aggcontext;
+#endif
 	else if (fcinfo->context && IsA(fcinfo->context, WindowAggState))
 		aggcontext = ((WindowAggState *) fcinfo->context)->aggcontext;
 
