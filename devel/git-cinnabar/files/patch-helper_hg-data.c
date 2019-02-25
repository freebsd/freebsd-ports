../helper/hg-data.c:44:59: error: too few arguments to function call, expected 5, have 4
                content = read_object_file_extended(note, &type, &len, 0);
                          ~~~~~~~~~~~~~~~~~~~~~~~~~                     ^
./object-store.h:165:1: note: 'read_object_file_extended' declared here
extern void *read_object_file_extended(struct repository *r,
^
../helper/hg-data.c:58:58: error: too few arguments to function call, expected 5, have 4
        content = read_object_file_extended(note, &type, &len, 0);
                  ~~~~~~~~~~~~~~~~~~~~~~~~~                     ^
./object-store.h:165:1: note: 'read_object_file_extended' declared here
extern void *read_object_file_extended(struct repository *r,
^

--- helper/hg-data.c.orig	2018-12-26 23:01:43 UTC
+++ helper/hg-data.c
@@ -41,7 +41,7 @@ void hg_file_load(struct hg_file *result, const unsign
 	ensure_notes(&files_meta);
 	note = get_note(&files_meta, &oid);
 	if (note) {
-		content = read_object_file_extended(note, &type, &len, 0);
+		content = read_object_file_extended(the_repository, note, &type, &len, 0);
 		strbuf_add(&result->file, "\1\n", 2);
 		strbuf_add(&result->file, content, len);
 		strbuf_add(&result->file, "\1\n", 2);
@@ -55,7 +55,7 @@ void hg_file_load(struct hg_file *result, const unsign
 	if (!note)
 		die("Missing data");
 
-	content = read_object_file_extended(note, &type, &len, 0);
+	content = read_object_file_extended(the_repository, note, &type, &len, 0);
 	strbuf_add(&result->file, content, len);
 	free(content);
 
