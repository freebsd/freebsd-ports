--- filters/kword/pdf/xpdf/xpdf/Catalog.cc.orig	2004-10-18 16:26:39.388666476 +0200
+++ filters/kword/pdf/xpdf/xpdf/Catalog.cc	2004-10-18 16:27:28.004749073 +0200
@@ -62,6 +62,12 @@
   }
   pagesSize = numPages0 = obj.getInt();
   obj.free();
+  if (pagesSize*sizeof(Page *)/sizeof(Page *) != pagesSize ||
+      pagesSize*sizeof(Ref)/sizeof(Ref) != pagesSize) {
+    error(-1, "Invalid 'pagesSize'");
+    ok = gFalse;
+    return;
+  }
   pages = (Page **)gmalloc(pagesSize * sizeof(Page *));
   pageRefs = (Ref *)gmalloc(pagesSize * sizeof(Ref));
   for (i = 0; i < pagesSize; ++i) {
@@ -186,6 +192,11 @@
       }
       if (start >= pagesSize) {
 	pagesSize += 32;
+        if (pagesSize*sizeof(Page *)/sizeof(Page *) != pagesSize ||
+            pagesSize*sizeof(Ref)/sizeof(Ref) != pagesSize) {
+          error(-1, "Invalid 'pagesSize' parameter.");
+          goto err3;
+        }
 	pages = (Page **)grealloc(pages, pagesSize * sizeof(Page *));
 	pageRefs = (Ref *)grealloc(pageRefs, pagesSize * sizeof(Ref));
 	for (j = pagesSize - 32; j < pagesSize; ++j) {
