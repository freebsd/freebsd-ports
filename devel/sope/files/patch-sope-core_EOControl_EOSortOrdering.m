--- sope-core/EOControl/EOSortOrdering.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOSortOrdering.m
@@ -28,14 +28,6 @@
 #  include <objc/objc.h>
 #endif
 
-#ifndef SEL_EQ
-#  if GNU_RUNTIME
-#    define SEL_EQ(sel1,sel2) sel_eq(sel1,sel2)
-#  else
-#    define SEL_EQ(sel1,sel2) (sel1 == sel2)
-#  endif
-#endif
-
 @implementation EOSortOrdering
 /*"
   This class specifies a sort-ordering as used with
@@ -83,7 +75,7 @@
 /* equality */
 
 - (BOOL)isEqualToSortOrdering:(EOSortOrdering *)_sortOrdering {
-  if (!SEL_EQ([_sortOrdering selector], [self selector]))
+  if (!sel_eq([_sortOrdering selector], [self selector]))
     return NO;
   if (![[_sortOrdering key] isEqualToString:[self key]])
     return NO;
