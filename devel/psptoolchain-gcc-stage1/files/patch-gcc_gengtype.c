--- gcc/gengtype.c.orig	2010-11-25 19:03:27.000000000 +0000
+++ gcc/gengtype.c
@@ -3594,14 +3594,13 @@ write_field_root (outf_p f, pair_p v, ty
 		  int has_length, struct fileloc *line, const char *if_marked,
 		  bool emit_pch, type_p field_type, const char *field_name)
 {
+  struct pair newv;
   /* If the field reference is relative to V, rather than to some
      subcomponent of V, we can mark any subarrays with a single stride.
      We're effectively treating the field as a global variable in its
      own right.  */
   if (v && type == v->type)
     {
-      struct pair newv;
-
       newv = *v;
       newv.type = field_type;
       newv.name = ACONCAT ((v->name, ".", field_name, NULL));
