--- src/query.c.orig	Mon May 24 20:30:42 2004
+++ src/query.c	Mon May 24 20:30:55 2004
@@ -74,12 +74,12 @@
 
 	while (1)
 	{
+		GttBucket *bu;
 		/* Check error bounds, should never happen */
 		if ((0 > arr_day) || (arr_day >= da->array_len))
 		{
 			return 1;
 		}
-		GttBucket *bu;
 		bu = &g_array_index (da->buckets, GttBucket, arr_day);
 
 		stm.tm_mday ++;
