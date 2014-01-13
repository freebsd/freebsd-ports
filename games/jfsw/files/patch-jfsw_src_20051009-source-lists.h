--- jfsw_src_20051009/source/lists.h.orig	2005-10-09 15:28:24.000000000 +0200
+++ jfsw_src_20051009/source/lists.h	2005-10-10 15:02:08.000000000 +0200
@@ -57,7 +57,7 @@
                                      ((LIST) nodep)->Next->Prev = ((LIST) nodep)->Prev)
 
 
-      #define TRAVERSE(l, o, n)    ASSERT(((LIST)l)->Next && ((LIST)l)->Prev); for ((LIST) o = ((LIST)l)->Next;      \
+      #define TRAVERSE(l, o, n)    ASSERT(((LIST)l)->Next && ((LIST)l)->Prev); for (o = ((LIST)l)->Next;      \
                                       n = o->Next, (LIST) o != (LIST) l; \
                                       o = n)
 
