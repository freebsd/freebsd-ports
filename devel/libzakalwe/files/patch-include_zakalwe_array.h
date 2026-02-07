--- include/zakalwe/array.h.orig	2022-10-06 20:04:46 UTC
+++ include/zakalwe/array.h
@@ -13,7 +13,7 @@ extern "C" {
 extern "C" {
 #endif
 
-static inline void *z_array_util_double_if_needed(void *ptr,
+static inline void *z_array_util_double_if_needed(void **ptr,
 						  const size_t num_members,
 						  size_t *num_allocated,
 						  const size_t size)
@@ -24,10 +24,14 @@ static inline void *z_array_util_double_if_needed(void
 	if (!z_mul2_size_t(&new_num_allocated, *num_allocated, 2))
 		return NULL;
 	new_num_allocated = Z_MAX(new_num_allocated, 1);
-	ptr = reallocarray(ptr, new_num_allocated, size);
-	if (ptr != NULL)
-		*num_allocated = new_num_allocated;
-	return ptr;
+	// ptr = reallocarray(ptr, new_num_allocated, size);
+	void *new_ptr = realloc(*ptr, new_num_allocated * size);
+	if (new_ptr == NULL)
+		return NULL;
+
+	*ptr = new_ptr;
+	*num_allocated = new_num_allocated;
+	return new_ptr;
 }
 
 int _z_array_allocate(const size_t new_num_items,
