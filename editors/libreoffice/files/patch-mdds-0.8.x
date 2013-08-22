--- sc/source/core/data/dpfilteredcache.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ sc/source/core/data/dpfilteredcache.cxx	2013-08-16 18:29:17.000000000 -0400
@@ -185,7 +185,7 @@
         {
             if (nRow > nEndSegment)
             {
-                if (!maShowByFilter.search_tree(nRow, bShow, NULL, &nEndSegment))
+                if (!maShowByFilter.search_tree(nRow, bShow, NULL, &nEndSegment).second)
                 {
                     OSL_FAIL("Tree search failed!");
                     continue;
--- sc/source/core/data/segmenttree.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ sc/source/core/data/segmenttree.cxx	2013-08-16 18:29:17.000000000 -0400
@@ -159,7 +159,7 @@
     if (!maSegments.is_tree_valid())
         maSegments.build_tree();
 
-    if (!maSegments.search_tree(nPos, nValue, &nPos1, &nPos2))
+    if (!maSegments.search_tree(nPos, nValue, &nPos1, &nPos2).second)
         return false;
 
     rData.mnPos1 = nPos1;
--- sc/source/filter/excel/colrowst.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ sc/source/filter/excel/colrowst.cxx	2013-08-16 18:29:17.000000000 -0400
@@ -208,7 +208,7 @@
         if (GetColFlag(nCol, EXC_COLROW_USED))
         {
             sal_uInt16 nTmp;
-            if (maColWidths.search_tree(nCol, nTmp))
+            if (maColWidths.search_tree(nCol, nTmp).second)
                 nWidth = nTmp;
         }
 
@@ -258,7 +258,7 @@
                     for (SCROW i = nPrevRow; i <= nRow - 1; ++i)
                     {
                         SCROW nLast;
-                        if (!maRowHeights.search_tree(i, nHeight, NULL, &nLast))
+                        if (!maRowHeights.search_tree(i, nHeight, NULL, &nLast).second)
                         {
                             // search failed for some reason
                             return;
--- sc/source/filter/xml/XMLStylesExportHelper.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ sc/source/filter/xml/XMLStylesExportHelper.cxx	2013-08-16 18:29:17.000000000 -0400
@@ -1290,7 +1290,7 @@
         r.build_tree();
     sal_Int32 nStyle;
     sal_Int32 nStart, nEnd;
-    if (r.search_tree(nField, nStyle, &nStart, &nEnd))
+    if (r.search_tree(nField, nStyle, &nStart, &nEnd).second)
     {
         // Cache this value for better performance.
         maCache.mnTable = nTable;
