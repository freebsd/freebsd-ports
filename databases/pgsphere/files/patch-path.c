--- path.c.orig	2019-10-30 10:18:38 UTC
+++ path.c
@@ -513,13 +513,21 @@ spherepath_in(PG_FUNCTION_ARGS)
 	nelem = get_path_count();
 	if (nelem > 1)
 	{
-		SPoint		arr[nelem];
+		SPoint*		arr = (SPoint*)malloc(nelem*sizeof(SPoint));
+		if (arr == NULL) {
+			reset_buffer();
+			elog(ERROR, "spherepath_in: could not allocate array");
+			PG_RETURN_NULL();
+		}
 
 		for (i = 0; i < nelem; i++)
 		{
 			get_path_elem(i, &arr[i].lng, &arr[i].lat);
 		}
 		path = spherepath_from_array(&arr[0], nelem);
+
+		//free array
+		free(arr);
 	}
 	else
 	{
