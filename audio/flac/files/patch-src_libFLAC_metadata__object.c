
$FreeBSD$

--- src/libFLAC/metadata_object.c.orig
+++ src/libFLAC/metadata_object.c
@@ -35,6 +35,7 @@
 #include "private/metadata.h"
 
 #include "FLAC/assert.h"
+#include "share/alloc.h"
 
 
 /****************************************************************************
@@ -47,7 +48,7 @@
 {
 	if(bytes > 0 && 0 != from) {
 		FLAC__byte *x;
-		if(0 == (x = (FLAC__byte*)malloc(bytes)))
+		if(0 == (x = (FLAC__byte*)safe_malloc_(bytes)))
 			return false;
 		memcpy(x, from, bytes);
 		*to = x;
@@ -62,7 +63,7 @@
 
 static FLAC__bool ensure_null_terminated_(FLAC__byte **entry, unsigned length)
 {
-	FLAC__byte *x = (FLAC__byte*)realloc(*entry, length+1);
+	FLAC__byte *x = (FLAC__byte*)safe_realloc_add_2op_(*entry, length, /*+*/1);
 	if(0 != x) {
 		x[length] = '\0';
 		*entry = x;
@@ -82,7 +83,7 @@
 	else {
 		FLAC__byte *x;
 		FLAC__ASSERT(from->length > 0);
-		if(0 == (x = (FLAC__byte*)malloc(from->length+1)))
+		if(0 == (x = (FLAC__byte*)safe_malloc_add_2op_(from->length, /*+*/1)))
 			return false;
 		memcpy(x, from->entry, from->length);
 		x[from->length] = '\0';
@@ -100,7 +101,7 @@
 	else {
 		FLAC__StreamMetadata_CueSheet_Index *x;
 		FLAC__ASSERT(from->num_indices > 0);
-		if(0 == (x = (FLAC__StreamMetadata_CueSheet_Index*)malloc(from->num_indices * sizeof(FLAC__StreamMetadata_CueSheet_Index))))
+		if(0 == (x = (FLAC__StreamMetadata_CueSheet_Index*)safe_malloc_mul_2op_(from->num_indices, /*times*/sizeof(FLAC__StreamMetadata_CueSheet_Index))))
 			return false;
 		memcpy(x, from->indices, from->num_indices * sizeof(FLAC__StreamMetadata_CueSheet_Index));
 		to->indices = x;
@@ -122,7 +123,7 @@
 
 	FLAC__ASSERT(num_points > 0);
 
-	object_array = (FLAC__StreamMetadata_SeekPoint*)malloc(num_points * sizeof(FLAC__StreamMetadata_SeekPoint));
+	object_array = (FLAC__StreamMetadata_SeekPoint*)safe_malloc_mul_2op_(num_points, /*times*/sizeof(FLAC__StreamMetadata_SeekPoint));
 
 	if(0 != object_array) {
 		unsigned i;
@@ -155,7 +156,7 @@
 {
 	FLAC__ASSERT(num_comments > 0);
 
-	return (FLAC__StreamMetadata_VorbisComment_Entry*)calloc(num_comments, sizeof(FLAC__StreamMetadata_VorbisComment_Entry));
+	return (FLAC__StreamMetadata_VorbisComment_Entry*)safe_calloc_(num_comments, sizeof(FLAC__StreamMetadata_VorbisComment_Entry));
 }
 
 static void vorbiscomment_entry_array_delete_(FLAC__StreamMetadata_VorbisComment_Entry *object_array, unsigned num_comments)
@@ -294,14 +295,14 @@
 {
 	FLAC__ASSERT(num_indices > 0);
 
-	return (FLAC__StreamMetadata_CueSheet_Index*)calloc(num_indices, sizeof(FLAC__StreamMetadata_CueSheet_Index));
+	return (FLAC__StreamMetadata_CueSheet_Index*)safe_calloc_(num_indices, sizeof(FLAC__StreamMetadata_CueSheet_Index));
 }
 
 static FLAC__StreamMetadata_CueSheet_Track *cuesheet_track_array_new_(unsigned num_tracks)
 {
 	FLAC__ASSERT(num_tracks > 0);
 
-	return (FLAC__StreamMetadata_CueSheet_Track*)calloc(num_tracks, sizeof(FLAC__StreamMetadata_CueSheet_Track));
+	return (FLAC__StreamMetadata_CueSheet_Track*)safe_calloc_(num_tracks, sizeof(FLAC__StreamMetadata_CueSheet_Track));
 }
 
 static void cuesheet_track_array_delete_(FLAC__StreamMetadata_CueSheet_Track *object_array, unsigned num_tracks)
@@ -462,6 +463,10 @@
 				break;
 			case FLAC__METADATA_TYPE_SEEKTABLE:
 				to->data.seek_table.num_points = object->data.seek_table.num_points;
+				if(to->data.seek_table.num_points > SIZE_MAX / sizeof(FLAC__StreamMetadata_SeekPoint)) { /* overflow check */
+					FLAC__metadata_object_delete(to);
+					return 0;
+				}
 				if(!copy_bytes_((FLAC__byte**)&to->data.seek_table.points, (FLAC__byte*)object->data.seek_table.points, object->data.seek_table.num_points * sizeof(FLAC__StreamMetadata_SeekPoint))) {
 					FLAC__metadata_object_delete(to);
 					return 0;
@@ -788,8 +793,12 @@
 			return false;
 	}
 	else {
-		const unsigned old_size = object->data.seek_table.num_points * sizeof(FLAC__StreamMetadata_SeekPoint);
-		const unsigned new_size = new_num_points * sizeof(FLAC__StreamMetadata_SeekPoint);
+		const size_t old_size = object->data.seek_table.num_points * sizeof(FLAC__StreamMetadata_SeekPoint);
+		const size_t new_size = new_num_points * sizeof(FLAC__StreamMetadata_SeekPoint);
+
+		/* overflow check */
+		if((size_t)new_num_points > SIZE_MAX / sizeof(FLAC__StreamMetadata_SeekPoint))
+			return false;
 
 		FLAC__ASSERT(object->data.seek_table.num_points > 0);
 
@@ -982,8 +991,12 @@
 			return false;
 	}
 	else {
-		const unsigned old_size = object->data.vorbis_comment.num_comments * sizeof(FLAC__StreamMetadata_VorbisComment_Entry);
-		const unsigned new_size = new_num_comments * sizeof(FLAC__StreamMetadata_VorbisComment_Entry);
+		const size_t old_size = object->data.vorbis_comment.num_comments * sizeof(FLAC__StreamMetadata_VorbisComment_Entry);
+		const size_t new_size = new_num_comments * sizeof(FLAC__StreamMetadata_VorbisComment_Entry);
+
+		/* overflow check */
+		if((size_t)new_num_comments > SIZE_MAX / sizeof(FLAC__StreamMetadata_VorbisComment_Entry))
+			return false;
 
 		FLAC__ASSERT(object->data.vorbis_comment.num_comments > 0);
 
@@ -1131,7 +1144,7 @@
 		const size_t nn = strlen(field_name);
 		const size_t nv = strlen(field_value);
 		entry->length = nn + 1 /*=*/ + nv;
-		if(0 == (entry->entry = (FLAC__byte*)malloc(entry->length+1)))
+		if(0 == (entry->entry = (FLAC__byte*)safe_malloc_add_2op_(entry->length, /*+*/1)))
 			return false;
 		memcpy(entry->entry, field_name, nn);
 		entry->entry[nn] = '=';
@@ -1158,9 +1171,9 @@
 		FLAC__ASSERT(0 != eq);
 		if(0 == eq)
 			return false; /* double protection */
-		if(0 == (*field_name = (char*)malloc(nn+1)))
+		if(0 == (*field_name = (char*)safe_malloc_add_2op_(nn, /*+*/1)))
 			return false;
-		if(0 == (*field_value = (char*)malloc(nv+1))) {
+		if(0 == (*field_value = (char*)safe_malloc_add_2op_(nv, /*+*/1))) {
 			free(*field_name);
 			return false;
 		}
@@ -1290,8 +1303,12 @@
 			return false;
 	}
 	else {
-		const unsigned old_size = track->num_indices * sizeof(FLAC__StreamMetadata_CueSheet_Index);
-		const unsigned new_size = new_num_indices * sizeof(FLAC__StreamMetadata_CueSheet_Index);
+		const size_t old_size = track->num_indices * sizeof(FLAC__StreamMetadata_CueSheet_Index);
+		const size_t new_size = new_num_indices * sizeof(FLAC__StreamMetadata_CueSheet_Index);
+
+		/* overflow check */
+		if((size_t)new_num_indices > SIZE_MAX / sizeof(FLAC__StreamMetadata_CueSheet_Index))
+			return false;
 
 		FLAC__ASSERT(track->num_indices > 0);
 
@@ -1374,8 +1391,12 @@
 			return false;
 	}
 	else {
-		const unsigned old_size = object->data.cue_sheet.num_tracks * sizeof(FLAC__StreamMetadata_CueSheet_Track);
-		const unsigned new_size = new_num_tracks * sizeof(FLAC__StreamMetadata_CueSheet_Track);
+		const size_t old_size = object->data.cue_sheet.num_tracks * sizeof(FLAC__StreamMetadata_CueSheet_Track);
+		const size_t new_size = new_num_tracks * sizeof(FLAC__StreamMetadata_CueSheet_Track);
+
+		/* overflow check */
+		if((size_t)new_num_tracks > SIZE_MAX / sizeof(FLAC__StreamMetadata_CueSheet_Track))
+			return false;
 
 		FLAC__ASSERT(object->data.cue_sheet.num_tracks > 0);
 
