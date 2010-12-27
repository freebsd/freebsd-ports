--- ProjectFilesDialog.cpp.orig	2010-04-03 23:47:33.000000000 +0400
+++ ProjectFilesDialog.cpp	2010-12-10 20:05:23.000000000 +0300
@@ -677,6 +677,17 @@
 	endRemoveRows();
 }
 
+namespace {
+  struct less_for_first_members_of_pairs
+  {
+    template <typename Pair>
+    bool operator()(Pair const& left, Pair const& right) const
+    {
+      return left.first < right.first;
+    }
+  };
+}
+
 void
 ProjectFilesDialog::FileList::remove(QItemSelection const& selection)
 {
@@ -699,7 +710,8 @@
 	);
 	std::sort(
 		sorted_ranges.begin(), sorted_ranges.end(),
-		bind(&Range::first, _1) < bind(&Range::first, _2)
+		// bind(&Range::first, _1) < bind(&Range::first, _2)
+		less_for_first_members_of_pairs()
 	);
 	
 	QVectorIterator<Range> it(sorted_ranges);
