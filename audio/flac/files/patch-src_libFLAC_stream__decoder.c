
$FreeBSD$

--- src/libFLAC/stream_decoder.c.orig
+++ src/libFLAC/stream_decoder.c
@@ -46,6 +46,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include "share/alloc.h"
 
 #ifdef max
 #undef max
@@ -214,7 +215,7 @@
 	}
 
 	decoder->private_->metadata_filter_ids_capacity = 16;
-	if(0 == (decoder->private_->metadata_filter_ids = (FLAC__byte*)malloc((FLAC__STREAM_METADATA_APPLICATION_ID_LEN/8) * decoder->private_->metadata_filter_ids_capacity))) {
+	if(0 == (decoder->private_->metadata_filter_ids = (FLAC__byte*)safe_malloc_mul_2op_((FLAC__STREAM_METADATA_APPLICATION_ID_LEN/8), /*times*/decoder->private_->metadata_filter_ids_capacity))) {
 		FLAC__bitbuffer_delete(decoder->private_->input);
 		free(decoder->private_);
 		free(decoder->protected_);
@@ -455,7 +456,7 @@
 	FLAC__ASSERT(0 != decoder->private_->metadata_filter_ids);
 
 	if(decoder->private_->metadata_filter_ids_count == decoder->private_->metadata_filter_ids_capacity) {
-		if(0 == (decoder->private_->metadata_filter_ids = (FLAC__byte*)realloc(decoder->private_->metadata_filter_ids, decoder->private_->metadata_filter_ids_capacity * 2)))
+		if(0 == (decoder->private_->metadata_filter_ids = (FLAC__byte*)safe_realloc_mul_2op_(decoder->private_->metadata_filter_ids, decoder->private_->metadata_filter_ids_capacity, /*times*/2)))
 			return decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 		decoder->private_->metadata_filter_ids_capacity *= 2;
 	}
@@ -512,7 +513,7 @@
 	FLAC__ASSERT(0 != decoder->private_->metadata_filter_ids);
 
 	if(decoder->private_->metadata_filter_ids_count == decoder->private_->metadata_filter_ids_capacity) {
-		if(0 == (decoder->private_->metadata_filter_ids = (FLAC__byte*)realloc(decoder->private_->metadata_filter_ids, decoder->private_->metadata_filter_ids_capacity * 2)))
+		if(0 == (decoder->private_->metadata_filter_ids = (FLAC__byte*)safe_realloc_mul_2op_(decoder->private_->metadata_filter_ids, decoder->private_->metadata_filter_ids_capacity, /*times*/2)))
 			return decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 		decoder->private_->metadata_filter_ids_capacity *= 2;
 	}
@@ -804,7 +805,7 @@
 		 * (at negative indices) for alignment purposes; we use 4
 		 * to keep the data well-aligned.
 		 */
-		tmp = (FLAC__int32*)malloc(sizeof(FLAC__int32)*(size+4));
+		tmp = (FLAC__int32*)safe_malloc_mul_2op_(sizeof(FLAC__int32), /*times*/(size+4));
 		if(tmp == 0) {
 			decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 			return false;
@@ -967,7 +968,7 @@
 				case FLAC__METADATA_TYPE_APPLICATION:
 					/* remember, we read the ID already */
 					if(real_length > 0) {
-						if(0 == (block.data.application.data = (FLAC__byte*)malloc(real_length))) {
+						if(0 == (block.data.application.data = (FLAC__byte*)safe_malloc_(real_length))) {
 							decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 							return false;
 						}
@@ -991,7 +992,7 @@
 					break;
 				default:
 					if(real_length > 0) {
-						if(0 == (block.data.unknown.data = (FLAC__byte*)malloc(real_length))) {
+						if(0 == (block.data.unknown.data = (FLAC__byte*)safe_malloc_(real_length))) {
 							decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 							return false;
 						}
@@ -1132,7 +1133,7 @@
 	decoder->private_->seek_table.data.seek_table.num_points = length / FLAC__STREAM_METADATA_SEEKPOINT_LENGTH;
 
 	/* use realloc since we may pass through here several times (e.g. after seeking) */
-	if(0 == (decoder->private_->seek_table.data.seek_table.points = (FLAC__StreamMetadata_SeekPoint*)realloc(decoder->private_->seek_table.data.seek_table.points, decoder->private_->seek_table.data.seek_table.num_points * sizeof(FLAC__StreamMetadata_SeekPoint)))) {
+	if(0 == (decoder->private_->seek_table.data.seek_table.points = (FLAC__StreamMetadata_SeekPoint*)safe_realloc_mul_2op_(decoder->private_->seek_table.data.seek_table.points, decoder->private_->seek_table.data.seek_table.num_points, /*times*/sizeof(FLAC__StreamMetadata_SeekPoint)))) {
 		decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 		return false;
 	}
@@ -1171,7 +1172,7 @@
 	if(!FLAC__bitbuffer_read_raw_uint32_little_endian(decoder->private_->input, &obj->vendor_string.length, read_callback_, decoder))
 		return false; /* the read_callback_ sets the state for us */
 	if(obj->vendor_string.length > 0) {
-		if(0 == (obj->vendor_string.entry = (FLAC__byte*)malloc(obj->vendor_string.length+1))) {
+		if(0 == (obj->vendor_string.entry = (FLAC__byte*)safe_malloc_add_2op_(obj->vendor_string.length, /*+*/1))) {
 			decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 			return false;
 		}
@@ -1189,7 +1190,7 @@
 
 	/* read comments */
 	if(obj->num_comments > 0) {
-		if(0 == (obj->comments = (FLAC__StreamMetadata_VorbisComment_Entry*)malloc(obj->num_comments * sizeof(FLAC__StreamMetadata_VorbisComment_Entry)))) {
+		if(0 == (obj->comments = (FLAC__StreamMetadata_VorbisComment_Entry*)safe_malloc_mul_2op_(obj->num_comments, /*times*/sizeof(FLAC__StreamMetadata_VorbisComment_Entry)))) {
 			decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 			return false;
 		}
@@ -1198,7 +1199,7 @@
 			if(!FLAC__bitbuffer_read_raw_uint32_little_endian(decoder->private_->input, &obj->comments[i].length, read_callback_, decoder))
 				return false; /* the read_callback_ sets the state for us */
 			if(obj->comments[i].length > 0) {
-				if(0 == (obj->comments[i].entry = (FLAC__byte*)malloc(obj->comments[i].length+1))) {
+				if(0 == (obj->comments[i].entry = (FLAC__byte*)safe_malloc_add_2op_(obj->comments[i].length, /*+*/1))) {
 					decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 					return false;
 				}
@@ -1244,7 +1245,7 @@
 	obj->num_tracks = x;
 
 	if(obj->num_tracks > 0) {
-		if(0 == (obj->tracks = (FLAC__StreamMetadata_CueSheet_Track*)calloc(obj->num_tracks, sizeof(FLAC__StreamMetadata_CueSheet_Track)))) {
+		if(0 == (obj->tracks = (FLAC__StreamMetadata_CueSheet_Track*)safe_calloc_(obj->num_tracks, sizeof(FLAC__StreamMetadata_CueSheet_Track)))) {
 			decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 			return false;
 		}
@@ -1277,7 +1278,7 @@
 			track->num_indices = (FLAC__byte)x;
 
 			if(track->num_indices > 0) {
-				if(0 == (track->indices = (FLAC__StreamMetadata_CueSheet_Index*)calloc(track->num_indices, sizeof(FLAC__StreamMetadata_CueSheet_Index)))) {
+				if(0 == (track->indices = (FLAC__StreamMetadata_CueSheet_Index*)safe_calloc_(track->num_indices, sizeof(FLAC__StreamMetadata_CueSheet_Index)))) {
 					decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
 					return false;
 				}
