--- lib/repository_admin.c.orig	2023-06-24 15:03:03 UTC
+++ lib/repository_admin.c
@@ -620,7 +620,7 @@ got_repo_cleanup_prepare(struct got_repository *repo,
     struct got_lockfile **lk)
 {
 	const struct got_error *err;
-	char myname[HOST_NAME_MAX + 1];
+	char myname[_POSIX_HOST_NAME_MAX + 1];
 
 	if (gethostname(myname, sizeof(myname)) == -1)
 		return got_error_from_errno("gethostname");
