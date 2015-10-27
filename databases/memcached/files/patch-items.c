--- items.c.orig	2015-10-27 17:57:02 UTC
+++ items.c
@@ -1138,7 +1138,6 @@ static item *crawler_crawl_q(item *it) {
     item **head, **tail;
     assert(it->it_flags == 1);
     assert(it->nbytes == 0);
-    assert(it->slabs_clsid < LARGEST_ID);
     head = &heads[it->slabs_clsid];
     tail = &tails[it->slabs_clsid];
 
