From 4a8e36d20609f1f7918976d4db13d720524a3c9c Mon Sep 17 00:00:00 2001
From: Kohei Yoshida <kohei.yoshida@gmail.com>
Date: Mon, 06 May 2013 14:27:55 +0000
Subject: Adjust for API change in mdds 0.8.0.

The return value of search_tree() in flat_segment_tree has changed.

Change-Id: I51d8676bd0621bd43b3f8a8f6be4bf4056d45904
---
diff --git a/sc/source/core/data/dpfilteredcache.cxx b/sc/source/core/data/dpfilteredcache.cxx
index 47adbbe..51bf571 100644
--- sc/source/core/data/dpfilteredcache.cxx
+++ b/sc/source/core/data/dpfilteredcache.cxx
@@ -172,7 +172,7 @@ void ScDPFilteredCache::fillTable(
         {
             if (nRow > nEndSegment)
             {
-                if (!maShowByFilter.search_tree(nRow, bShow, NULL, &nEndSegment))
+                if (!maShowByFilter.search_tree(nRow, bShow, NULL, &nEndSegment).second)
                 {
                     OSL_FAIL("Tree search failed!");
                     continue;
diff --git a/sc/source/core/data/segmenttree.cxx b/sc/source/core/data/segmenttree.cxx
index e74b0fd..b02f164 100644
--- sc/source/core/data/segmenttree.cxx
+++ b/sc/source/core/data/segmenttree.cxx
@@ -159,7 +159,7 @@ bool ScFlatSegmentsImpl<_ValueType, _ExtValueType>::getRangeData(SCCOLROW nPos,
     if (!maSegments.is_tree_valid())
         maSegments.build_tree();
 
-    if (!maSegments.search_tree(nPos, nValue, &nPos1, &nPos2))
+    if (!maSegments.search_tree(nPos, nValue, &nPos1, &nPos2).second)
         return false;
 
     rData.mnPos1 = nPos1;
diff --git a/sc/source/filter/excel/colrowst.cxx b/sc/source/filter/excel/colrowst.cxx
index 53aa04b..bc43a1e 100644
--- sc/source/filter/excel/colrowst.cxx
+++ b/sc/source/filter/excel/colrowst.cxx
@@ -208,7 +208,7 @@ void XclImpColRowSettings::Convert( SCTAB nScTab )
         if (GetColFlag(nCol, EXC_COLROW_USED))
         {
             sal_uInt16 nTmp;
-            if (maColWidths.search_tree(nCol, nTmp))
+            if (maColWidths.search_tree(nCol, nTmp).second)
                 nWidth = nTmp;
         }
 
@@ -258,7 +258,7 @@ void XclImpColRowSettings::Convert( SCTAB nScTab )
                     for (SCROW i = nPrevRow; i <= nRow - 1; ++i)
                     {
                         SCROW nLast;
-                        if (!maRowHeights.search_tree(i, nHeight, NULL, &nLast))
+                        if (!maRowHeights.search_tree(i, nHeight, NULL, &nLast).second)
                         {
                             // search failed for some reason
                             return;
diff --git a/sc/source/filter/xml/XMLStylesExportHelper.cxx b/sc/source/filter/xml/XMLStylesExportHelper.cxx
index 4f7a937..cefa640 100644
--- sc/source/filter/xml/XMLStylesExportHelper.cxx
+++ b/sc/source/filter/xml/XMLStylesExportHelper.cxx
@@ -1280,7 +1280,7 @@ sal_Int32 ScRowStyles::GetStyleNameIndex(const sal_Int32 nTable, const sal_Int32
         r.build_tree();
     sal_Int32 nStyle;
     sal_Int32 nStart, nEnd;
-    if (r.search_tree(nField, nStyle, &nStart, &nEnd))
+    if (r.search_tree(nField, nStyle, &nStart, &nEnd).second)
     {
         // Cache this value for better performance.
         maCache.mnTable = nTable;
--
cgit v0.9.0.2-2-gbebe
