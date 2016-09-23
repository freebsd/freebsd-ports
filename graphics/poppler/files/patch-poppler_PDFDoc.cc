From: Albert Astals Cid <aacid@kde.org>
Date: Sat, 30 Jul 2016 17:32:59 +0200
Subject: Fix abort on documents where the docinfo obj is not a dict

Bug #97134

--- poppler/PDFDoc.cc.orig	2016-07-05 21:37:01 UTC
+++ poppler/PDFDoc.cc
@@ -646,7 +646,7 @@ void PDFDoc::setDocInfoStringEntry(const
 GooString *PDFDoc::getDocInfoStringEntry(const char *key) {
   Object infoObj;
   getDocInfo(&infoObj);
-  if (infoObj.isNull()) {
+  if (!infoObj.isDict()) {
       return NULL;
   }
 
