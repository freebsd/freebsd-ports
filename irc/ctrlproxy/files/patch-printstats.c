--- printstats.c.orig	Wed Oct 22 22:34:42 2003
+++ printstats.c	Wed Oct 22 22:34:48 2003
@@ -34,9 +34,9 @@
 
 int traverse_keys(TDB_CONTEXT *tdb_context, TDB_DATA key, TDB_DATA value, void *pattern)
 {
+	long *ivalue;
 	if(!key.dptr) return 0;
 
-	long *ivalue;
 	ivalue = (long *)value.dptr;
 	printf("%s: %ld\n", key.dptr, *ivalue);
 	return 0;
