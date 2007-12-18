--- contrib/meta/metaobj.c.orig	2007-12-17 19:32:36.000000000 +0100
+++ contrib/meta/metaobj.c	2007-12-17 19:33:01.000000000 +0100
@@ -851,7 +851,7 @@
  meta_world *w;
  meta_blob *b;
  ay_object *down;
- char *adapt;
+ const char *adapt;
  char vname[] = "ay";
  char vname1[] = "action";
  double euler[3] = {0};
