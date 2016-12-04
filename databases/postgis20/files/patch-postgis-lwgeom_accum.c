--- postgis/lwgeom_accum.c.orig	2012-02-27 22:08:12 UTC
+++ postgis/lwgeom_accum.c
@@ -106,7 +106,11 @@ pgis_geometry_accum_transfn(PG_FUNCTION_
 		         errmsg("could not determine input data type")));
 
 	if (fcinfo->context && IsA(fcinfo->context, AggState))
+#if POSTGIS_PGSQL_VERSION >= 95
+		aggcontext = ((AggState *) fcinfo->context)->aggcontexts;
+#else
 		aggcontext = ((AggState *) fcinfo->context)->aggcontext;
+#endif
 #if POSTGIS_PGSQL_VERSION == 84
 
 	else if (fcinfo->context && IsA(fcinfo->context, WindowAggState))
