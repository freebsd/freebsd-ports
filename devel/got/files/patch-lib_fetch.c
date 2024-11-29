Upstream commit 55569948434c65bb416f2d0f2a400a1bf3da5a78

--- lib/fetch.c.orig	2024-11-28 17:28:16 UTC
+++ lib/fetch.c
@@ -166,7 +166,7 @@ got_fetch_pack(struct got_object_id **pack_hash, struc
 
 	TAILQ_FOREACH(re, &my_refs, entry) {
 		struct got_object_id *id;
-		const char *refname;
+		char *refname;
 
 		if (got_ref_is_symbolic(re->ref))
 			continue;
@@ -183,7 +183,7 @@ got_fetch_pack(struct got_object_id **pack_hash, struc
 		if (err)
 			goto done;
 		if (new == NULL){
-			free(&refname);
+			free(refname);
 			free(id);
 		}
 
