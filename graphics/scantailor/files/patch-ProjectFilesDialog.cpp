--- ProjectFilesDialog.cpp.orig	2011-03-29 23:54:33.000000000 +0800
+++ ProjectFilesDialog.cpp	2011-03-30 00:04:45.000000000 +0800
@@ -677,6 +677,17 @@ ProjectFilesDialog::FileList::clear()
 	endRemoveRows();
 }
 
+namespace {
+	struct less_for_first_members_of_pairs
+	{
+		template <typename Pair>
+		bool operator()(Pair const& left, Pair const& right) const
+	{
+	return left.first < right.first;
+	}
+	};
+}
+
 void
 ProjectFilesDialog::FileList::remove(QItemSelection const& selection)
 {
@@ -703,7 +714,9 @@ ProjectFilesDialog::FileList::remove(QIt
 	
 	std::sort(
 		sorted_ranges.begin(), sorted_ranges.end(),
-		bind((IntMemPtr)&Range::first, _1) < bind((IntMemPtr)&Range::first, _2)
+		//bind((IntMemPtr)&Range::first, _1) < bind((IntMemPtr)&Range::first, _2)
+		less_for_first_members_of_pairs()
+
 	);
 	
 	QVectorIterator<Range> it(sorted_ranges);
