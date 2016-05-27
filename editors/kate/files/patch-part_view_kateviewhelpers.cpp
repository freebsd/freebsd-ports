--- part/view/kateviewhelpers.cpp.orig	2014-10-26 20:17:55 UTC
+++ part/view/kateviewhelpers.cpp
@@ -1532,7 +1532,7 @@ void KateIconBorder::paintBorder (int /*
   uint startz = (y / h);
   uint endz = startz + 1 + (height / h);
   uint lineRangesSize = m_viewInternal->cache()->viewCacheLineCount();
-  uint currentLine = m_view->cursorPosition().line();
+  int currentLine = m_view->cursorPosition().line();
 
   // center the folding boxes
   int m_px = (h - 11) / 2;
