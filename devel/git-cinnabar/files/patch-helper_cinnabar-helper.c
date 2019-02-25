../helper/cinnabar-helper.c:585:23: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
        oidcpy(&result->git, entry.oid);
                             ^~~~~~~~~
                             &
./cache.h:1075:74: note: passing argument to parameter 'src' here
static inline void oidcpy(struct object_id *dst, const struct object_id *src)
                                                                         ^
../helper/cinnabar-helper.c:592:22: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
        oidcpy(&result->hg, entry.oid);
                            ^~~~~~~~~
                            &
./cache.h:1075:74: note: passing argument to parameter 'src' here
static inline void oidcpy(struct object_id *dst, const struct object_id *src)
                                                                         ^
../helper/cinnabar-helper.c:670:14: error: assigning to 'const struct object_id *' from incompatible type
      'struct object_id'; take the address with &
        result->oid = entry_hg.oid;
                    ^ ~~~~~~~~~~~~
                      &
../helper/cinnabar-helper.c:679:20: error: assigning to 'const struct object_id *' from incompatible type
      'struct object_id'; take the address with &
        result->other_oid = entry_git.oid;
                          ^ ~~~~~~~~~~~~~
                            &
../helper/cinnabar-helper.c:707:21: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                        recurse_manifest(entry.oid, manifest,
                                         ^~~~~~~~~
                                         &
../helper/cinnabar-helper.c:685:54: note: passing argument to parameter 'tree_id' here
static void recurse_manifest(const struct object_id *tree_id,
                                                     ^
../helper/cinnabar-helper.c:716:26: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                            oid_to_hex(entry.oid), hgattr(entry.mode));
                                       ^~~~~~~~~
                                       &
./cache.h:1405:42: note: passing argument to parameter 'oid' here
char *oid_to_hex(const struct object_id *oid);                                          /* same static buffer */
                                         ^
../helper/cinnabar-helper.c:729:43: error: passing 'const struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
        return (e1->mode == e2->mode) && (oidcmp(e1->oid, e2->oid) == 0);
                                                 ^~~~~~~
                                                 &
./cache.h:1039:50: note: passing argument to parameter 'oid1' here
static inline int oidcmp(const struct object_id *oid1, const struct object_id *oid2)
                                                 ^
../helper/cinnabar-helper.c:829:27: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                                    oid_to_hex(cur_entry.oid),
                                               ^~~~~~~~~~~~~
                                               &
./cache.h:1405:42: note: passing argument to parameter 'oid' here
char *oid_to_hex(const struct object_id *oid);                                          /* same static buffer */
                                         ^
../helper/cinnabar-helper.c:839:22: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                        recurse_manifest2(ref_entry.oid, ref_manifest,
                                          ^~~~~~~~~~~~~
                                          &
../helper/cinnabar-helper.c:747:55: note: passing argument to parameter 'ref_tree_id' here
static void recurse_manifest2(const struct object_id *ref_tree_id,
                                                      ^
../helper/cinnabar-helper.c:843:21: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                        recurse_manifest(cur_entry.oid, manifest,
                                         ^~~~~~~~~~~~~
                                         &
../helper/cinnabar-helper.c:685:54: note: passing argument to parameter 'tree_id' here
static void recurse_manifest(const struct object_id *tree_id,
                                                     ^
../helper/cinnabar-helper.c:1452:57: error: too few arguments to function call, expected 5, have 4
                        content = read_object_file_extended(note, &t, &len, 0);
                                  ~~~~~~~~~~~~~~~~~~~~~~~~~                  ^
./object-store.h:165:1: note: 'read_object_file_extended' declared here
extern void *read_object_file_extended(struct repository *r,
^
../helper/cinnabar-helper.c:1577:16: error: non-pointer operand type 'struct object_id' incompatible with NULL
                                        ref_entry ? ref_entry->oid : NULL,
                                                  ^ ~~~~~~~~~~~~~~
../helper/cinnabar-helper.c:1581:36: error: member reference type 'struct object_id' is not a pointer; did you
      mean to use '.'?
                                strbuf_add(&tree_buf, entry.oid->hash, 20);
                                                      ~~~~~~~~~^~
                                                               .
../helper/cinnabar-helper.c:1636:16: error: non-pointer operand type 'struct object_id' incompatible with NULL
                                        ref_entry ? ref_entry->oid : NULL,
                                                  ^ ~~~~~~~~~~~~~~
../helper/cinnabar-helper.c:1918:6: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                                        entry.oid, NULL, tree_buf, NULL,
                                        ^~~~~~~~~
                                        &
../helper/cinnabar-helper.c:1883:61: note: passing argument to parameter 'tree_id' here
static void recurse_create_git_tree(const struct object_id *tree_id,
                                                            ^
../helper/cinnabar-helper.c:1927:16: error: non-pointer operand type 'struct object_id' incompatible with NULL
                                        ref_entry ? ref_entry->oid : NULL,
                                                  ^ ~~~~~~~~~~~~~~
../helper/cinnabar-helper.c:1931:35: error: member reference type 'struct object_id' is not a pointer; did you
      mean to use '.'?
                                if (is_empty_hg_file(entry.oid->hash))
                                                     ~~~~~~~~~^~
                                                              .
../helper/cinnabar-helper.c:1934:32: error: passing 'struct object_id' to parameter of incompatible type
      'const struct object_id *'; take the address with &
                                        file_oid = resolve_hg2git(entry.oid, 40);
                                                                  ^~~~~~~~~
                                                                  &
../helper/cinnabar-helper.c:470:71: note: passing argument to parameter 'oid' here
static const struct object_id *resolve_hg2git(const struct object_id *oid,
                                                                      ^

--- helper/cinnabar-helper.c.orig	2019-02-25 13:51:46 UTC
+++ helper/cinnabar-helper.c
@@ -282,7 +282,7 @@ static void do_ls_tree(struct string_list *args)
 		goto not_found;
 
 	memset(&match_all, 0, sizeof(match_all));
-	read_tree_recursive(tree, "", 0, 0, &match_all, fill_ls_tree, &ctx);
+	read_tree_recursive(the_repository, tree, "", 0, 0, &match_all, fill_ls_tree, &ctx);
 	send_buffer(&ctx.buf);
 	strbuf_release(&ctx.buf);
 
@@ -582,14 +582,14 @@ static int get_old_manifest_tree(struct tree *tree,
 		goto not_found;
 	if (strcmp(entry.path, "git"))
 		goto not_found;
-	oidcpy(&result->git, entry.oid);
+	oidcpy(&result->git, &entry.oid);
 
 	/* The second entry in the manifest tree is the hg subtree. */
 	if (!tree_entry(&desc, &entry))
 		goto not_found;
 	if (strcmp(entry.path, "hg"))
 		goto not_found;
-	oidcpy(&result->hg, entry.oid);
+	oidcpy(&result->hg, &entry.oid);
 
 	/* There shouldn't be any other entry. */
 	if (tree_entry(&desc, &entry))
@@ -667,7 +667,7 @@ static int old_manifest_tree_entry(struct old_manifest
 		return 0;
 	}
 
-	result->oid = entry_hg.oid;
+	result->oid = &entry_hg.oid;
 	result->path = entry_hg.path;
 	result->mode = entry_git.mode;
 	if (strcmp(entry_hg.path, entry_git.path))
@@ -676,7 +676,7 @@ static int old_manifest_tree_entry(struct old_manifest
 		if (entry_git.mode != entry_hg.mode)
 			goto corrupted;
 	}
-	result->other_oid = entry_git.oid;
+	result->other_oid = &entry_git.oid;
 	return 1;
 corrupted:
 	die("Corrupted metadata");
@@ -704,7 +704,7 @@ static void recurse_manifest(const struct object_id *t
 			strbuf_addslice(&dir, base);
 			strbuf_addslice(&dir, entry_path);
 			strbuf_addch(&dir, '/');
-			recurse_manifest(entry.oid, manifest,
+			recurse_manifest(&entry.oid, manifest,
 			                 strbuf_as_slice(&dir), tree_list);
 			strbuf_release(&dir);
 			continue;
@@ -713,7 +713,7 @@ static void recurse_manifest(const struct object_id *t
 		strbuf_addslice(manifest, base);
 		strbuf_addslice(manifest, entry_path);
 		strbuf_addf(manifest, "%c%s%s\n", '\0',
-		            oid_to_hex(entry.oid), hgattr(entry.mode));
+		            oid_to_hex(&entry.oid), hgattr(entry.mode));
 	}
 
 	return;
@@ -726,7 +726,7 @@ corrupted:
 static int manifest_entry_equal(const struct name_entry *e1,
                                 const struct name_entry *e2)
 {
-	return (e1->mode == e2->mode) && (oidcmp(e1->oid, e2->oid) == 0);
+	return (e1->mode == e2->mode) && (oidcmp(&e1->oid, &e2->oid) == 0);
 }
 
 /* Return whether base + name matches path */
@@ -826,7 +826,7 @@ static void recurse_manifest2(const struct object_id *
 			strbuf_addslice(manifest, strslice_slice(
 				cur_entry_path, 1, SIZE_MAX));
 			strbuf_addf(manifest, "%c%s%s\n", '\0',
-			            oid_to_hex(cur_entry.oid),
+			            oid_to_hex(&cur_entry.oid),
 			            hgattr(cur_entry.mode));
 			continue;
 		}
@@ -836,11 +836,11 @@ static void recurse_manifest2(const struct object_id *
 			cur_entry_path, 1, SIZE_MAX));
 		strbuf_addch(&dir, '/');
 		if (cmp == 0 && S_ISDIR(ref_entry.mode)) {
-			recurse_manifest2(ref_entry.oid, ref_manifest,
-				          cur_entry.oid, manifest,
+			recurse_manifest2(&ref_entry.oid, ref_manifest,
+				          &cur_entry.oid, manifest,
 			                  strbuf_as_slice(&dir), tree_list);
 		} else
-			recurse_manifest(cur_entry.oid, manifest,
+			recurse_manifest(&cur_entry.oid, manifest,
 			                 strbuf_as_slice(&dir), tree_list);
 		strbuf_release(&dir);
 	}
@@ -1449,7 +1449,7 @@ static void upgrade_files(const struct old_manifest_tr
 			unsigned long len;
 			enum object_type t;
 			char *content;
-			content = read_object_file_extended(note, &t, &len, 0);
+			content = read_object_file_extended(the_repository, note, &t, &len, 0);
 			strbuf_attach(&buf, content, len, len);
 			hg_file_init(&file);
 			hg_file_from_memory(&file, entry.oid->hash, &buf);
@@ -1573,12 +1573,12 @@ static void upgrade_manifest_tree_v1(const struct obje
 					&ref_state, reference, entry_buf.buf);
 				strbuf_reset(&entry_buf);
 				upgrade_manifest_tree_v1(
-					entry.oid,
-					ref_entry ? ref_entry->oid : NULL,
+					&entry.oid,
+					ref_entry ? &ref_entry->oid : NULL,
 					&new_subtree, cache);
 				strbuf_add(&tree_buf, new_subtree.hash, 20);
 			} else {
-				strbuf_add(&tree_buf, entry.oid->hash, 20);
+				strbuf_add(&tree_buf, entry.oid.hash, 20);
 			}
 		}
 
@@ -1633,7 +1633,7 @@ static void upgrade_manifest_tree(struct old_manifest_
 				oidcpy(&subtree.hg, entry.oid);
 				upgrade_manifest_tree(
 					&subtree,
-					ref_entry ? ref_entry->oid : NULL,
+					ref_entry ? &ref_entry->oid : NULL,
 					&oid, cache);
 			} else {
 				if (S_ISLNK(mode))
@@ -1915,7 +1915,7 @@ static void recurse_create_git_tree(const struct objec
 				if (!S_ISDIR(mode))
 					goto corrupted;
 				recurse_create_git_tree(
-					entry.oid, NULL, tree_buf, NULL,
+					&entry.oid, NULL, tree_buf, NULL,
 					cache);
 				continue;
 			} else if (S_ISDIR(mode)) {
@@ -1923,15 +1923,15 @@ static void recurse_create_git_tree(const struct objec
 				ref_entry = lazy_tree_entry_by_name(
 					&ref_state, reference, entry_path.buf);
 				recurse_create_git_tree(
-					entry.oid,
-					ref_entry ? ref_entry->oid : NULL,
+					&entry.oid,
+					ref_entry ? &ref_entry->oid : NULL,
 					NULL, &oid, cache);
 			} else {
 				const struct object_id *file_oid;
-				if (is_empty_hg_file(entry.oid->hash))
+				if (is_empty_hg_file(entry.oid.hash))
 					file_oid = ensure_empty_blob();
 				else
-					file_oid = resolve_hg2git(entry.oid, 40);
+					file_oid = resolve_hg2git(&entry.oid, 40);
 				if (!file_oid)
 					goto corrupted;
 				oidcpy(&oid, file_oid);
