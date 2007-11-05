--- fw/TTextView.cpp.orig	2007-11-03 00:01:15.000000000 +0100
+++ fw/TTextView.cpp	2007-11-03 00:01:40.000000000 +0100
@@ -451,7 +451,7 @@
 		{
 			if (offset < fSelectionAnchor)
 			{
-				selectionStart = selectionStart = fLayout->GetLineOffset(fLayout->OffsetToLine(offset));
+				selectionStart = fLayout->GetLineOffset(fLayout->OffsetToLine(offset));
 				selectionEnd = fSelectionAnchorEnd;
 			}
 			else if (offset > fSelectionAnchorEnd)
