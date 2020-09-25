--- libexec/got-index-pack/got-index-pack.c.orig	2020-09-25 11:58:47 UTC
+++ libexec/got-index-pack/got-index-pack.c
@@ -246,7 +246,7 @@ read_packed_object(struct got_pack *pack, struct got_i
 			free(data);
 			break;
 		}
-		if (asprintf(&header, "%s %lld", obj_label, obj->size) == -1) {
+		if (asprintf(&header, "%s %lld", obj_label, (long long)obj->size) == -1) {
 			err = got_error_from_errno("asprintf");
 			free(data);
 			break;
