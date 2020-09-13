--- polygon.c.orig	2019-10-30 10:18:38 UTC
+++ polygon.c
@@ -824,13 +824,21 @@ spherepoly_in(PG_FUNCTION_ARGS)
 	nelem = get_path_count();
 	if (nelem > 2)
 	{
-		SPoint		arr[nelem];
+		// allocate arr
+		SPoint* arr = (SPoint *)malloc(nelem * sizeof(SPoint));
+		if (arr == NULL) {
+			reset_buffer();
+			elog(ERROR, "spherepoly_in: Could not allocate array.");
+			PG_RETURN_NULL();
+		}
 
 		for (i = 0; i < nelem; i++)
 		{
 			get_path_elem(i, &arr[i].lng, &arr[i].lat);
 		}
 		poly = spherepoly_from_array(&arr[0], nelem);
+		// free allocated array
+		free(arr);
 	}
 	else
 	{
@@ -892,11 +900,17 @@ spherepoly_area(PG_FUNCTION_ARGS)
 {
 	SPOLY	   *poly = PG_GETARG_SPOLY(0);
 	int32		i;
-	SPoint		s[poly->npts + 2];
+	SPoint     *s = (SPoint*)malloc((poly->npts+2)*sizeof(SPoint));
+	//SPoint		s[poly->npts + 2];
 	SPoint		stmp[2];
 	SEuler		se;
 	float8		sum = 0.0;
 
+	if (s == NULL) {
+		elog(ERROR, "spherepoly_area: Could not allocate array.");
+		PG_RETURN_NULL();
+	}
+
 	memcpy((void *) &s[1],
 		   (void *) &poly->p[0],
 		   poly->npts * sizeof(SPoint));
@@ -935,6 +949,9 @@ spherepoly_area(PG_FUNCTION_ARGS)
 	{
 		sum = 0.0;
 	}
+
+	// free array
+	free(s);
 
 	PG_RETURN_FLOAT8(sum);
 }
