--- prefcnt.c.orig	2016-06-30 19:30:28 UTC
+++ prefcnt.c
@@ -66,9 +66,11 @@ static void refcnt_tag(struct tag *tag, 
 
 	tag->visited = 1;
 
-	if (tag__is_struct(tag) || tag__is_union(tag))
-		type__for_each_member(tag__type(tag), member)
+	if (tag__is_struct(tag) || tag__is_union(tag)) {
+		type__for_each_member(tag__type(tag), member) {
 			refcnt_member(member, cu);
+		}
+	}
 }
 
 static void refcnt_lexblock(const struct lexblock *lexblock, const struct cu *cu)
