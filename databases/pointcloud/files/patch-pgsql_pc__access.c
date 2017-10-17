--- pgsql/pc_access.c.orig	2015-08-09 08:58:06 UTC
+++ pgsql/pc_access.c
@@ -315,7 +315,7 @@ Datum pointcloud_agg_transfn(PG_FUNCTION
 
 	if (fcinfo->context && IsA(fcinfo->context, AggState))
 	{
-		aggcontext = ((AggState *) fcinfo->context)->aggcontext;
+		aggcontext = ((AggState *) fcinfo->context)->aggcontexts;
 	}
 	else if (fcinfo->context && IsA(fcinfo->context, WindowAggState))
 	{
