--- FL/Selection.H.orig	Wed Sep  3 19:03:20 2003
+++ FL/Selection.H	Wed Sep  3 19:03:27 2003
@@ -17,7 +17,7 @@
 private:
 	class SelectionRange
 	{
-	friend Selection;
+	friend class Selection;
 	private:
 		int mFrom;
 		int mTo;
