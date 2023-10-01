--- lib/repository.c.orig	2023-09-29 20:30:16 UTC
+++ lib/repository.c
@@ -947,6 +947,8 @@ got_repo_remote_repo_dup(struct got_remote_repo **newp
 
 	new->mirror_references = repo->mirror_references;
 
+	new->fetch_all_branches = repo->fetch_all_branches;
+
 	new->nfetch_branches = repo->nfetch_branches;
 	if (repo->fetch_branches) {
 		new->fetch_branches = calloc(repo->nfetch_branches,
