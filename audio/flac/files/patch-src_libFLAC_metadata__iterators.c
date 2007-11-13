
$FreeBSD$

--- src/libFLAC/metadata_iterators.c.orig
+++ src/libFLAC/metadata_iterators.c
@@ -48,6 +48,7 @@
 
 #include "FLAC/assert.h"
 #include "FLAC/file_decoder.h"
+#include "share/alloc.h"
 
 #ifdef max
 #undef max
@@ -1928,7 +1929,7 @@
 		block->data = 0;
 	}
 	else {
-		if(0 == (block->data = (FLAC__byte*)malloc(block_length)))
+		if(0 == (block->data = (FLAC__byte*)safe_malloc_(block_length)))
 			return FLAC__METADATA_SIMPLE_ITERATOR_STATUS_MEMORY_ALLOCATION_ERROR;
 
 		if(read_cb(block->data, 1, block_length, handle) != block_length)
@@ -1949,7 +1950,7 @@
 
 	if(block->num_points == 0)
 		block->points = 0;
-	else if(0 == (block->points = (FLAC__StreamMetadata_SeekPoint*)malloc(block->num_points * sizeof(FLAC__StreamMetadata_SeekPoint))))
+	else if(0 == (block->points = (FLAC__StreamMetadata_SeekPoint*)safe_malloc_mul_2op_(block->num_points, /*times*/ sizeof(FLAC__StreamMetadata_SeekPoint))))
 		return FLAC__METADATA_SIMPLE_ITERATOR_STATUS_MEMORY_ALLOCATION_ERROR;
 
 	for(i = 0; i < block->num_points; i++) {
@@ -1982,7 +1983,7 @@
 		entry->entry = 0;
 	}
 	else {
-		if(0 == (entry->entry = (FLAC__byte*)malloc(entry->length+1)))
+		if(0 == (entry->entry = (FLAC__byte*)safe_malloc_add_2op_(entry->length, /*+*/1)))
 			return FLAC__METADATA_SIMPLE_ITERATOR_STATUS_MEMORY_ALLOCATION_ERROR;
 
 		if(read_cb(entry->entry, 1, entry->length, handle) != entry->length)
@@ -2145,7 +2146,7 @@
 		block->data = 0;
 	}
 	else {
-		if(0 == (block->data = (FLAC__byte*)malloc(block_length)))
+		if(0 == (block->data = (FLAC__byte*)safe_malloc_(block_length)))
 			return FLAC__METADATA_SIMPLE_ITERATOR_STATUS_MEMORY_ALLOCATION_ERROR;
 
 		if(read_cb(block->data, 1, block_length, handle) != block_length)
@@ -2812,7 +2813,7 @@
 {
 	static const char *tempfile_suffix = ".metadata_edit";
 	if(0 == tempfile_path_prefix) {
-		if(0 == (*tempfilename = (char*)malloc(strlen(filename) + strlen(tempfile_suffix) + 1))) {
+		if(0 == (*tempfilename = (char*)safe_malloc_add_3op_(strlen(filename), /*+*/strlen(tempfile_suffix), /*+*/1))) {
 			*status = FLAC__METADATA_SIMPLE_ITERATOR_STATUS_MEMORY_ALLOCATION_ERROR;
 			return false;
 		}
@@ -2826,7 +2827,7 @@
 		else
 			p++;
 
-		if(0 == (*tempfilename = (char*)malloc(strlen(tempfile_path_prefix) + 1 + strlen(p) + strlen(tempfile_suffix) + 1))) {
+		if(0 == (*tempfilename = (char*)safe_malloc_add_4op_(strlen(tempfile_path_prefix), /*+*/strlen(p), /*+*/strlen(tempfile_suffix), /*+*/2))) {
 			*status = FLAC__METADATA_SIMPLE_ITERATOR_STATUS_MEMORY_ALLOCATION_ERROR;
 			return false;
 		}
