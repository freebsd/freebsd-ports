--- vigra/include/vigra/diff2d.hxx.orig	2008-02-14 23:14:15.000000000 +0000
+++ vigra/include/vigra/diff2d.hxx	2012-09-24 12:02:46.539117586 +0000
@@ -1131,7 +1131,7 @@
     bool contains(Rect2D const &r) const
     {
         return r.isEmpty() ||
-            contains(r.upperLeft()) && contains(r.lowerRight()-Diff2D(1,1));
+            (contains(r.upperLeft()) && contains(r.lowerRight()-Diff2D(1,1)));
     }
 
         /** Return whether this rectangle overlaps with the given
