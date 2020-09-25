--- lib/worktree.c.orig	2020-09-25 11:58:47 UTC
+++ lib/worktree.c
@@ -1227,7 +1227,7 @@ replace_existing_symlink(const char *ondisk_path, cons
 	 */
 	fd = open(ondisk_path, O_RDWR | O_EXCL | O_NOFOLLOW);
 	if (fd == -1) {
-		if (errno != ELOOP)
+		if (errno != ELOOP && errno != EMLINK)
 			return got_error_from_errno2("open", ondisk_path);
 
 		/* We are updating an existing on-disk symlink. */
@@ -1703,9 +1703,9 @@ get_file_status(unsigned char *status, struct stat *sb
 		}
 	} else {
 		fd = open(abspath, O_RDONLY | O_NOFOLLOW);
-		if (fd == -1 && errno != ENOENT && errno != ELOOP)
+		if (fd == -1 && errno != ENOENT && errno != ELOOP && errno != EMLINK)
 			return got_error_from_errno2("open", abspath);
-		else if (fd == -1 && errno == ELOOP) {
+		else if (fd == -1 && (errno == ELOOP || errno == EMLINK)) {
 			if (lstat(abspath, sb) == -1)
 				return got_error_from_errno2("lstat", abspath);
 		} else if (fd == -1 || fstat(fd, sb) == -1) {
@@ -3518,7 +3518,7 @@ worktree_status(struct got_worktree *worktree, const c
 	fd = open(ondisk_path, O_RDONLY | O_NOFOLLOW | O_DIRECTORY);
 	if (fd == -1) {
 		if (errno != ENOTDIR && errno != ENOENT && errno != EACCES &&
-		    errno != ELOOP)
+		    errno != ELOOP && errno != EMLINK)
 			err = got_error_from_errno2("open", ondisk_path);
 		else
 			err = report_single_file_status(path, ondisk_path,
@@ -4190,7 +4190,7 @@ create_patched_content(char **path_outfile, int revers
 	if (dirfd2 != -1) {
 		fd2 = openat(dirfd2, de_name2, O_RDONLY | O_NOFOLLOW);
 		if (fd2 == -1) {
-			if (errno != ELOOP) {
+			if (errno != ELOOP && errno != EMLINK) {
 				err = got_error_from_errno2("openat", path2);
 				goto done;
 			}
@@ -4204,7 +4204,7 @@ create_patched_content(char **path_outfile, int revers
 	} else {
 		fd2 = open(path2, O_RDONLY | O_NOFOLLOW);
 		if (fd2 == -1) {
-			if (errno != ELOOP) {
+			if (errno != ELOOP && errno != EMLINK) {
 				err = got_error_from_errno2("open", path2);
 				goto done;
 			}
