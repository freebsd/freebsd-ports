--- Object.xs.orig	Tue Jul 18 18:37:35 2006
+++ Object.xs	Tue Jul 18 18:39:19 2006
@@ -52,6 +52,9 @@
 	       ? iset_insert_one(s, item) \
                : iset_insert_scalar(s, item) )
 
+void _dispel_magic(ISET*, SV*);
+void _cast_magic(ISET*, SV*);
+
 int insert_in_bucket(BUCKET* pb, SV* sv)
 {
 	if (!pb->sv)
