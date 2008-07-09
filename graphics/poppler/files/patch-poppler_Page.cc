--- poppler/Page.cc.orig	2008-07-09 17:53:56.000000000 +0200
+++ poppler/Page.cc	2008-07-09 17:54:49.000000000 +0200
@@ -230,7 +230,7 @@
 
 Page::Page(XRef *xrefA, int numA, Dict *pageDict, PageAttrs *attrsA, Form *form) {
   Object tmp;
-	
+  pageWidgets =	NULL;
   ok = gTrue;
   xref = xrefA;
   num = numA;
