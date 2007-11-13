
$FreeBSD$

--- src/plugin_common/tags.c.orig
+++ src/plugin_common/tags.c
@@ -23,6 +23,7 @@
 #include "tags.h"
 #include "FLAC/assert.h"
 #include "FLAC/metadata.h"
+#include "share/alloc.h"
 
 
 static __inline unsigned local__wide_strlen(const FLAC__uint16 *s)
@@ -82,7 +83,7 @@
 	}
 
 	/* allocate */
-	out = (FLAC__uint16*)malloc(chars * sizeof(FLAC__uint16));
+	out = (FLAC__uint16*)safe_malloc_mul_2op_(chars, /*times*/sizeof(FLAC__uint16));
 	if (0 == out) {
 		FLAC__ASSERT(0);
 		return 0;
@@ -130,19 +131,23 @@
 static char *local__convert_ucs2_to_utf8(const FLAC__uint16 *src, unsigned length)
 {
 	char *out;
-	unsigned len = 0;
+	unsigned len = 0, n;
 
 	FLAC__ASSERT(0 != src);
 
 	/* calculate length */
 	{
 		unsigned i;
-		for (i = 0; i < length; i++)
-			len += local__ucs2len(src[i]);
+		for (i = 0; i < length; i++) {
+			n += local__ucs2len(src[i]);
+			if(len + n < len) /* overflow check */
+				return 0;
+			len += n;
+		}
 	}
 
 	/* allocate */
-	out = (char*)malloc(len * sizeof(char));
+	out = (char*)safe_malloc_mul_2op_(len, /*times*/sizeof(char));
 	if (0 == out)
 		return 0;
 
@@ -265,7 +270,7 @@
 		const size_t value_len = strlen(value);
 		const size_t separator_len = strlen(separator);
 		FLAC__byte *new_entry;
-		if(0 == (new_entry = (FLAC__byte*)realloc(entry->entry, entry->length + value_len + separator_len + 1)))
+		if(0 == (new_entry = (FLAC__byte*)safe_realloc_add_4op_(entry->entry, entry->length, /*+*/value_len, /*+*/separator_len, /*+*/1)))
 			return false;
 		memcpy(new_entry+entry->length, separator, separator_len);
 		entry->length += separator_len;
