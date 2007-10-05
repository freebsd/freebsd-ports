--- biewlib/tw_class.c.orig	2007-10-04 15:14:56.000000000 +0200
+++ biewlib/tw_class.c	2007-10-04 15:15:16.000000000 +0200
@@ -71,6 +71,6 @@
 TwClass * __FASTCALL__ twcFindClass(const char *name)
 {
  TwClass key;
- (const char *)(key.name) = name;
+ key.name = name;
  return (TwClass *)la_Find(class_set,&key, comp_class);
 }
