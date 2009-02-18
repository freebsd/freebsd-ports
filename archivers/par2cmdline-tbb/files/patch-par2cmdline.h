--- par2cmdline.h.orig	2008-05-01 08:53:49.729467641 +0200
+++ par2cmdline.h	2008-05-01 08:54:02.616707220 +0200
@@ -443,7 +443,7 @@
                   incrementing_parallel_while_with_max> >& w,
     ITEM* item)
   {
-    const size_t n = item->is_first() ? tbb::DetectNumberOfWorkers() : 1;
+    const size_t n = item->is_first() ? tbb::internal::DetectNumberOfWorkers() : 1;
 
     bool res = false;
     std::pair<bool, size_t> pr(w.increment_next_i());
