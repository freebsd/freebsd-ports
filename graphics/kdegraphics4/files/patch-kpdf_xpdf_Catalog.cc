--- kpdf/xpdf/Catalog.cc	20 Aug 2003 21:25:12 -0000	1.3
+++ kpdf/xpdf/Catalog.cc	18 Oct 2004 20:12:09 -0000
@@ -61,10 +61,16 @@ Catalog::Catalog(XRef *xrefA) {
 	  obj.getTypeName());
     goto err3;
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
     pages[i] = NULL;
     pageRefs[i].num = -1;
@@ -188,10 +194,15 @@ int Catalog::readPageTree(Dict *pagesDic
 	++start;
 	goto err3;
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
 	  pages[j] = NULL;
 	  pageRefs[j].num = -1;