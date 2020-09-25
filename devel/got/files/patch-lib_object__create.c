--- lib/object_create.c.orig	2020-09-25 11:58:47 UTC
+++ lib/object_create.c
@@ -131,7 +131,7 @@ got_object_blob_file_create(struct got_object_id **id,
 
 	fd = open(ondisk_path, O_RDONLY | O_NOFOLLOW);
 	if (fd == -1) {
-		if (errno != ELOOP)
+		if (errno != ELOOP && errno != EMLINK)
 			return got_error_from_errno2("open", ondisk_path);
 
 		if (lstat(ondisk_path, &sb) == -1) {
@@ -144,7 +144,7 @@ got_object_blob_file_create(struct got_object_id **id,
 	}
 
 	if (asprintf(&header, "%s %lld", GOT_OBJ_LABEL_BLOB,
-		sb.st_size) == -1) {
+		(long long)sb.st_size) == -1) {
 		err = got_error_from_errno("asprintf");
 		goto done;
 	}
@@ -440,12 +440,12 @@ got_object_commit_create(struct got_object_id **id,
 	}
 
 	if (asprintf(&author_str, "%s%s %lld +0000\n",
-	    GOT_COMMIT_LABEL_AUTHOR, author, author_time) == -1)
+	    GOT_COMMIT_LABEL_AUTHOR, author, (long long)author_time) == -1)
 		return got_error_from_errno("asprintf");
 
 	if (asprintf(&committer_str, "%s%s %lld +0000\n",
 	    GOT_COMMIT_LABEL_COMMITTER, committer ? committer : author,
-	    committer ? committer_time : author_time)
+	    (long long)(committer ? committer_time : author_time))
 	    == -1) {
 		err = got_error_from_errno("asprintf");
 		goto done;
@@ -646,7 +646,7 @@ got_object_tag_create(struct got_object_id **id,
 	}
 
 	if (asprintf(&tagger_str, "%s%s %lld +0000\n",
-	    GOT_TAG_LABEL_TAGGER, tagger, tagger_time) == -1)
+	    GOT_TAG_LABEL_TAGGER, tagger, (long long)tagger_time) == -1)
 		return got_error_from_errno("asprintf");
 
 	msg0 = strdup(tagmsg);
