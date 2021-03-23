https://git.gameoftrees.org/gitweb/?p=got.git;a=commitdiff;h=4cc1f028ad995562d5037a1c8c54a241956d9dbb

--- lib/worktree.c.orig	2021-03-23 14:40:09 UTC
+++ lib/worktree.c
@@ -1733,6 +1733,7 @@ get_file_status(unsigned char *status, struct stat *sb
 	unsigned char staged_status = get_staged_status(ie);
 
 	*status = GOT_STATUS_NO_CHANGE;
+	memset(sb, 0, sizeof(*sb));
 
 	/*
 	 * Whenever the caller provides a directory descriptor and a
