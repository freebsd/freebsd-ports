--- got/got.c.orig	2020-09-14 13:58:27 UTC
+++ got/got.c
@@ -213,7 +213,8 @@ main(int argc, char *argv[])
 
 	argc -= optind;
 	argv += optind;
-	optind = 0;
+	optind = 1;
+	optreset = 1;
 
 	if (Vflag) {
 		got_version_print_str();
@@ -3884,7 +3885,7 @@ print_diff(void *arg, unsigned char status, unsigned c
 		if (dirfd != -1) {
 			fd = openat(dirfd, de_name, O_RDONLY | O_NOFOLLOW);
 			if (fd == -1) {
-				if (errno != ELOOP) {
+				if (errno != ELOOP && errno != EMLINK) {
 					err = got_error_from_errno2("openat",
 					    abspath);
 					goto done;
@@ -3897,7 +3898,7 @@ print_diff(void *arg, unsigned char status, unsigned c
 		} else {
 			fd = open(abspath, O_RDONLY | O_NOFOLLOW);
 			if (fd == -1) {
-				if (errno != ELOOP) {
+				if (errno != ELOOP && errno != EMLINK) {
 					err = got_error_from_errno2("open",
 					    abspath);
 					goto done;
@@ -9283,11 +9284,11 @@ cat_commit(struct got_object_id *id, struct got_reposi
 	}
 	fprintf(outfile, "%s%s %lld +0000\n", GOT_COMMIT_LABEL_AUTHOR,
 	    got_object_commit_get_author(commit),
-	    got_object_commit_get_author_time(commit));
+	    (long long)got_object_commit_get_author_time(commit));
 
 	fprintf(outfile, "%s%s %lld +0000\n", GOT_COMMIT_LABEL_COMMITTER,
 	    got_object_commit_get_author(commit),
-	    got_object_commit_get_committer_time(commit));
+	    (long long)got_object_commit_get_committer_time(commit));
 
 	logmsg = got_object_commit_get_logmsg_raw(commit);
 	fprintf(outfile, "messagelen %zd\n", strlen(logmsg));
@@ -9342,7 +9343,7 @@ cat_tag(struct got_object_id *id, struct got_repositor
 
 	fprintf(outfile, "%s%s %lld +0000\n", GOT_TAG_LABEL_TAGGER,
 	    got_object_tag_get_tagger(tag),
-	    got_object_tag_get_tagger_time(tag));
+	    (long long)got_object_tag_get_tagger_time(tag));
 
 	tagmsg = got_object_tag_get_message(tag);
 	fprintf(outfile, "messagelen %zd\n", strlen(tagmsg));
