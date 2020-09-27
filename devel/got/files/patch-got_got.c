--- got/got.c.orig	2020-09-25 11:58:47 UTC
+++ got/got.c
@@ -215,7 +215,8 @@ main(int argc, char *argv[])
 
 	argc -= optind;
 	argv += optind;
-	optind = 0;
+	optind = 1;
+	optreset = 1;
 
 	if (Vflag) {
 		got_version_print_str();
@@ -9421,11 +9422,11 @@ cat_commit(struct got_object_id *id, struct got_reposi
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
@@ -9480,7 +9481,7 @@ cat_tag(struct got_object_id *id, struct got_repositor
 
 	fprintf(outfile, "%s%s %lld +0000\n", GOT_TAG_LABEL_TAGGER,
 	    got_object_tag_get_tagger(tag),
-	    got_object_tag_get_tagger_time(tag));
+	    (long long)got_object_tag_get_tagger_time(tag));
 
 	tagmsg = got_object_tag_get_message(tag);
 	fprintf(outfile, "messagelen %zd\n", strlen(tagmsg));
