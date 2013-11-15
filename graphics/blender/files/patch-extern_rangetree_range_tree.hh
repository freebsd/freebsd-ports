--- extern/rangetree/range_tree.hh.orig	2013-11-12 09:41:41.000000000 +0100
+++ extern/rangetree/range_tree.hh	2013-11-12 21:47:07.000000000 +0100
@@ -35,6 +35,12 @@
 			: min(t), max(t), single(true)
 		{}
 
+                Range& operator=(const Range& v) {
+                        *this = v;
+                        return *this;
+                }
+
+
 		bool operator<(const Range& v) const {
 			return max < v.min;
 		}
