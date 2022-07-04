--- lib/sigs.c.orig	2022-07-04 14:54:12 UTC
+++ lib/sigs.c
@@ -206,7 +206,7 @@ got_tag_write_signed_data(BUF *buf, struct got_tag_obj
 	got_date_format_gmtoff(gmtoff, sizeof(gmtoff),
 	    got_object_tag_get_tagger_gmtoff(tag));
 	if (asprintf(&tagger, "%s %lld %s", got_object_tag_get_tagger(tag),
-	    got_object_tag_get_tagger_time(tag), gmtoff) == -1) {
+	    (long long)got_object_tag_get_tagger_time(tag), gmtoff) == -1) {
 		err = got_error_from_errno("asprintf");
 		goto done;
 	}
