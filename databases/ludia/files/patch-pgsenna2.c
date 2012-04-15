Fix from

http://decide.cocolog-nifty.com/blog/2009/03/postgresql-836-.html

to make it work with postgresql83

--- pgsenna2.c.orig	2012-03-27 18:32:05.393559930 +0100
+++ pgsenna2.c	2012-03-27 18:32:34.261558703 +0100
@@ -610,7 +610,7 @@
   bs.index = index_info_open(index, 1, flags);
   bs.oid_type = oid_type;
   reltuples = IndexBuildHeapScan(heap, index, indexInfo,
-                                 buildCallback, (void *) &bs);
+                                 buildCallback, (void *) &bs, false);
 #if defined(POSTGRES82) || defined(POSTGRES83)
   result = (IndexBuildResult *) PGS2_PALLOC(sizeof(IndexBuildResult));
   result->heap_tuples = reltuples;
