--- Object.xs.orig	2006-07-18 18:37:35 UTC
+++ Object.xs
@@ -89,6 +89,9 @@ START_MY_CXT
 int iset_remove_one(ISET* s, SV* el, int spell_in_progress);
 
 
+void _dispel_magic(ISET*, SV*);
+void _cast_magic(ISET*, SV*);
+
 int insert_in_bucket(BUCKET* pb, SV* sv)
 {
 	if (!pb->sv)
