--- util/permutedsort.c.orig	2015-12-12 19:02:27 UTC
+++ util/permutedsort.c
@@ -92,6 +92,12 @@ int* permuted_sort(const void* realarray
 	if (isnan(d2)) return -1;							\
 	assert(0); return 0;
 
+#define COMPARE_INT(d1, d2, op1, op2)					\
+	if (d1 op1 d2) return -1;							\
+	if (d1 op2 d2) return 1;							\
+	if (d1 == d2) return 0;								\
+	assert(0); return 0;
+
 	//printf("d1=%g, d2=%g\n", d1, d2);				   
 
 int compare_doubles_asc(const void* v1, const void* v2) {
@@ -122,13 +128,13 @@ int compare_floats_desc(const void* v1, 
 int compare_int64_asc(const void* v1, const void* v2) {
 	int64_t f1 = *(int64_t*)v1;
 	int64_t f2 = *(int64_t*)v2;
-	COMPARE(f1, f2, <, >);
+	COMPARE_INT(f1, f2, <, >);
 }
 
 int compare_int64_desc(const void* v1, const void* v2) {
 	int64_t f1 = *(int64_t*)v1;
 	int64_t f2 = *(int64_t*)v2;
-	COMPARE(f1, f2, >, <);
+	COMPARE_INT(f1, f2, >, <);
 }
 
 // Versions for use with QSORT_R
