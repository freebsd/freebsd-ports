--- sope-core/EOControl/EOSortOrdering.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOSortOrdering.m
@@ -29,7 +29,9 @@
 #endif
 
 #ifndef SEL_EQ
-#  if GNU_RUNTIME
+#  if defined(__GNUSTEP_RUNTIME__)
+#    define SEL_EQ(sel1,sel2) sel_isEqual(sel1, sel2)
+#  elif GNU_RUNTIME
 #    define SEL_EQ(sel1,sel2) sel_eq(sel1,sel2)
 #  else
 #    define SEL_EQ(sel1,sel2) (sel1 == sel2)
