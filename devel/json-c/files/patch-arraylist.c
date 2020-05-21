Obtained from:	https://github.com/json-c/json-c/commit/31243e4d1204ef78be34b0fcae73221eee6b83be

--- arraylist.c.orig	2020-04-19 03:36:00 UTC
+++ arraylist.c
@@ -136,6 +136,9 @@ int array_list_del_idx(struct array_list *arr, size_t 
 {
 	size_t i, stop;
 
+	/* Avoid overflow in calculation with large indices. */
+	if (idx > SIZE_T_MAX - count)
+		return -1;
 	stop = idx + count;
 	if (idx >= arr->length || stop > arr->length)
 		return -1;
