--- contrib/meta/metaobj.c.orig	2015-06-23 18:03:50 UTC
+++ contrib/meta/metaobj.c
@@ -859,7 +859,7 @@ metaobj_notifycb (ay_object *o)
  meta_world *w;
  meta_blob *b;
  ay_object *down;
- char *adapt;
+ const char *adapt;
  char vname[] = "ay";
  char vname1[] = "action";
  double euler[3] = {0};
