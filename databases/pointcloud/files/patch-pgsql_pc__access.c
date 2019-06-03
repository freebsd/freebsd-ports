--- pgsql/pc_access.c.orig	2018-08-22 09:36:04 UTC
+++ pgsql/pc_access.c
@@ -879,9 +879,9 @@ Datum pcpatch_intersects(PG_FUNCTION_ARGS)
 
 	if ( pc_bounds_intersects(&(serpa1->bounds), &(serpa2->bounds)) )
 	{
-		PG_RETURN_BOOL(TRUE);
+		PG_RETURN_BOOL(true);
 	}
-	PG_RETURN_BOOL(FALSE);
+	PG_RETURN_BOOL(false);
 }
 
 PG_FUNCTION_INFO_V1(pcpatch_size);
@@ -939,9 +939,9 @@ PG_FUNCTION_INFO_V1(pc_lazperf_enabled);
 Datum pc_lazperf_enabled(PG_FUNCTION_ARGS)
 {
 #ifdef HAVE_LAZPERF
-	PG_RETURN_BOOL(TRUE);
+	PG_RETURN_BOOL(true);
 #else
-	PG_RETURN_BOOL(FALSE);
+	PG_RETURN_BOOL(false);
 #endif
 }
 
