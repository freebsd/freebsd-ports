
$FreeBSD$

--- src/libFLAC/memory.c.orig
+++ src/libFLAC/memory.c
@@ -35,6 +35,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include "share/alloc.h"
 
 void *FLAC__memory_alloc_aligned(size_t bytes, void **aligned_address)
 {
@@ -44,10 +45,10 @@
 
 #ifdef FLAC__ALIGN_MALLOC_DATA
 	/* align on 32-byte (256-bit) boundary */
-	x = malloc(bytes+31);
+	x = safe_malloc_add_2op_(bytes, /*+*/31);
 	*aligned_address = (void*)(((unsigned)x + 31) & -32);
 #else
-	x = malloc(bytes);
+	x = safe_malloc_(bytes);
 	*aligned_address = x;
 #endif
 	return x;
@@ -66,6 +67,9 @@
 	FLAC__ASSERT(0 != aligned_pointer);
 	FLAC__ASSERT(unaligned_pointer != aligned_pointer);
 
+	if((size_t)elements > SIZE_MAX / sizeof(*pu)) /* overflow check */
+		return false;
+
 	pu = (FLAC__int32*)FLAC__memory_alloc_aligned(sizeof(FLAC__int32) * elements, &u.pv);
 	if(0 == pu) {
 		return false;
@@ -92,6 +96,9 @@
 	FLAC__ASSERT(0 != aligned_pointer);
 	FLAC__ASSERT(unaligned_pointer != aligned_pointer);
 
+	if((size_t)elements > SIZE_MAX / sizeof(*pu)) /* overflow check */
+		return false;
+
 	pu = (FLAC__uint32*)FLAC__memory_alloc_aligned(sizeof(FLAC__uint32) * elements, &u.pv);
 	if(0 == pu) {
 		return false;
@@ -118,6 +125,9 @@
 	FLAC__ASSERT(0 != aligned_pointer);
 	FLAC__ASSERT(unaligned_pointer != aligned_pointer);
 
+	if((size_t)elements > SIZE_MAX / sizeof(*pu)) /* overflow check */
+		return false;
+
 	pu = (FLAC__uint64*)FLAC__memory_alloc_aligned(sizeof(FLAC__uint64) * elements, &u.pv);
 	if(0 == pu) {
 		return false;
@@ -144,6 +154,9 @@
 	FLAC__ASSERT(0 != aligned_pointer);
 	FLAC__ASSERT(unaligned_pointer != aligned_pointer);
 
+	if((size_t)elements > SIZE_MAX / sizeof(*pu)) /* overflow check */
+		return false;
+
 	pu = (unsigned*)FLAC__memory_alloc_aligned(sizeof(unsigned) * elements, &u.pv);
 	if(0 == pu) {
 		return false;
@@ -171,6 +184,9 @@
 	FLAC__ASSERT(0 != unaligned_pointer);
 	FLAC__ASSERT(0 != aligned_pointer);
 	FLAC__ASSERT(unaligned_pointer != aligned_pointer);
+
+	if((size_t)elements > SIZE_MAX / sizeof(*pu)) /* overflow check */
+		return false;
 
 	pu = (FLAC__real*)FLAC__memory_alloc_aligned(sizeof(FLAC__real) * elements, &u.pv);
 	if(0 == pu) {
