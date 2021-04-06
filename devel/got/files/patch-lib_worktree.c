https://git.gameoftrees.org/gitweb/?p=got.git;a=commitdiff;h=c6e8a8268ec4f4240d51dcfd54d05c5370060747

--- lib/worktree.c.orig	2021-04-06 19:21:25 UTC
+++ lib/worktree.c
@@ -1246,14 +1246,16 @@ install_blob(struct got_worktree *worktree, const char
  * safe location in the work tree!
  */
 static const struct got_error *
-replace_existing_symlink(const char *ondisk_path, const char *target_path,
-    size_t target_len)
+replace_existing_symlink(int *did_something, const char *ondisk_path,
+    const char *target_path, size_t target_len)
 {
 	const struct got_error *err = NULL;
 	ssize_t elen;
 	char etarget[PATH_MAX];
 	int fd;
 
+	*did_something = 0;
+
 	/*
 	 * "Bad" symlinks (those pointing outside the work tree or into the
 	 * .got directory) are installed in the work tree as a regular file
@@ -1277,6 +1279,7 @@ replace_existing_symlink(const char *ondisk_path, cons
 			return NULL; /* nothing to do */
 	}
 
+	*did_something = 1;
 	err = update_symlink(ondisk_path, target_path, target_len);
 	if (fd != -1 && close(fd) == -1 && err == NULL)
 		err = got_error_from_errno2("close", ondisk_path);
@@ -1398,7 +1401,6 @@ install_symlink(int *is_bad_symlink, struct got_worktr
 
 	if (*is_bad_symlink) {
 		/* install as a regular file */
-		*is_bad_symlink = 1;
 		got_object_blob_rewind(blob);
 		err = install_blob(worktree, ondisk_path, path,
 		    GOT_DEFAULT_FILE_MODE, GOT_DEFAULT_FILE_MODE, blob,
@@ -1409,20 +1411,26 @@ install_symlink(int *is_bad_symlink, struct got_worktr
 
 	if (symlink(target_path, ondisk_path) == -1) {
 		if (errno == EEXIST) {
+			int symlink_replaced;
 			if (path_is_unversioned) {
 				err = (*progress_cb)(progress_arg,
 				    GOT_STATUS_UNVERSIONED, path);
 				goto done;
 			}
-			err = replace_existing_symlink(ondisk_path,
-			    target_path, target_len);
+			err = replace_existing_symlink(&symlink_replaced,
+			    ondisk_path, target_path, target_len);
 			if (err)
 				goto done;
 			if (progress_cb) {
-				err = (*progress_cb)(progress_arg,
-				    reverting_versioned_file ?
-				    GOT_STATUS_REVERT : GOT_STATUS_UPDATE,
-				    path);
+				if (symlink_replaced) {
+					err = (*progress_cb)(progress_arg,
+					    reverting_versioned_file ?
+					    GOT_STATUS_REVERT :
+					    GOT_STATUS_UPDATE, path);
+				} else {
+					err = (*progress_cb)(progress_arg,
+					    GOT_STATUS_EXISTS, path);
+				}
 			}
 			goto done; /* Nothing else to do. */
 		}
@@ -1930,11 +1938,19 @@ update_blob(struct got_worktree *worktree,
 		goto done;
 	}
 
-	if (ie && status != GOT_STATUS_MISSING &&
-	    (te->mode & S_IXUSR) == (sb.st_mode & S_IXUSR)) {
+	if (ie && status != GOT_STATUS_MISSING && S_ISREG(sb.st_mode) &&
+	    (S_ISLNK(te->mode) ||
+	    (te->mode & S_IXUSR) == (sb.st_mode & S_IXUSR))) {
+		/*
+		 * This is a regular file or an installed bad symlink.
+		 * If the file index indicates that this file is already
+		 * up-to-date with respect to the repository we can skip
+		 * updating contents of this file.
+		 */
 		if (got_fileindex_entry_has_commit(ie) &&
 		    memcmp(ie->commit_sha1, worktree->base_commit_id->sha1,
 		    SHA1_DIGEST_LENGTH) == 0) {
+			/* Same commit. */
 			err = sync_timestamps(worktree->root_fd,
 			    path, status, ie, &sb);
 			if (err)
@@ -1946,6 +1962,7 @@ update_blob(struct got_worktree *worktree,
 		if (got_fileindex_entry_has_blob(ie) &&
 		    memcmp(ie->blob_sha1, te->id.sha1,
 		    SHA1_DIGEST_LENGTH) == 0) {
+			/* Different commit but the same blob. */
 			err = sync_timestamps(worktree->root_fd,
 			    path, status, ie, &sb);
 			goto done;
