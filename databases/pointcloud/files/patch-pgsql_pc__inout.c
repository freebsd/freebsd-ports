--- pgsql/pc_inout.c.orig	2018-08-22 09:36:04 UTC
+++ pgsql/pc_inout.c
@@ -171,7 +171,7 @@ Datum pcschema_is_valid(PG_FUNCTION_ARGS)
 
 	if ( !schema )
 	{
-		PG_RETURN_BOOL(FALSE);
+		PG_RETURN_BOOL(false);
 	}
 
 	valid = pc_schema_is_valid(schema);
