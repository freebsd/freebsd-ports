../helper/cinnabar-fast-import.c:422:65: error: too few arguments to function call, expected 5, have 4
                char *content = read_object_file_extended(note, &type, &len, 0);
                                ~~~~~~~~~~~~~~~~~~~~~~~~~                     ^
./object-store.h:165:1: note: 'read_object_file_extended' declared here
extern void *read_object_file_extended(struct repository *r,
^
../helper/cinnabar-fast-import.c:435:47: error: too few arguments to function call, expected 5, have 4
                                                            &len, 0);
                                                                   ^
./object-store.h:165:1: note: 'read_object_file_extended' declared here
extern void *read_object_file_extended(struct repository *r,
^

--- helper/cinnabar-fast-import.c.orig	2018-12-26 23:01:43 UTC
+++ helper/cinnabar-fast-import.c
@@ -419,7 +419,7 @@ static void handle_changeset_conflict(struct object_id
 		struct object_id oid;
 		enum object_type type;
 		unsigned long len;
-		char *content = read_object_file_extended(note, &type, &len, 0);
+		char *content = read_object_file_extended(the_repository, note, &type, &len, 0);
 		if (len < 50 || !starts_with(content, "changeset ") ||
 		    get_oid_hex(&content[10], &oid))
 			die("Invalid git2hg note for %s", oid_to_hex(git_id));
@@ -431,7 +431,7 @@ static void handle_changeset_conflict(struct object_id
 			break;
 
 		if (!buf.len) {
-			content = read_object_file_extended(git_id, &type,
+			content = read_object_file_extended(the_repository, git_id, &type,
 			                                    &len, 0);
 			strbuf_add(&buf, content, len);
 			free(content);
