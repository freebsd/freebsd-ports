Index: kpdf/xpdf/Catalog.cc
===================================================================
RCS file: /home/kde/kdegraphics/kpdf/xpdf/Catalog.cc,v
retrieving revision 1.3.4.1
diff -u -5 -d -p -r1.3.4.1 Catalog.cc
--- kpdf/xpdf/Catalog.cc	2 Sep 2004 21:30:18 -0000	1.3.4.1
+++ kpdf/xpdf/Catalog.cc	12 Oct 2004 21:15:38 -0000
@@ -62,10 +62,19 @@ Catalog::Catalog(XRef *xrefA) {
 	  obj.getTypeName());
     goto err3;
   }
   pagesSize = numPages0 = (int)obj.getNum();
   obj.free();
+  // The gcc doesnt optimize this away, so this check is ok,
+  // even if it looks like a pagesSize != pagesSize check
+  if (pagesSize*sizeof(Page *)/sizeof(Page *) != pagesSize ||
+      pagesSize*sizeof(Ref)/sizeof(Ref) != pagesSize) {
+    error(-1, "Invalid 'pagesSize'");
+    ok = gFalse;
+    return;
+  }
+
   pages = (Page **)gmalloc(pagesSize * sizeof(Page *));
   pageRefs = (Ref *)gmalloc(pagesSize * sizeof(Ref));
   for (i = 0; i < pagesSize; ++i) {
     pages[i] = NULL;
     pageRefs[i].num = -1;
@@ -189,10 +198,14 @@ int Catalog::readPageTree(Dict *pagesDic
 	++start;
 	goto err3;
       }
       if (start >= pagesSize) {
 	pagesSize += 32;
+        if (pagesSize*sizeof(Page *)/sizeof(Page *) != pagesSize) {
+          error(-1, "Invalid 'pagesSize' parameter.");
+          goto err3;
+        }
 	pages = (Page **)grealloc(pages, pagesSize * sizeof(Page *));
 	pageRefs = (Ref *)grealloc(pageRefs, pagesSize * sizeof(Ref));
 	for (j = pagesSize - 32; j < pagesSize; ++j) {
 	  pages[j] = NULL;
 	  pageRefs[j].num = -1;
