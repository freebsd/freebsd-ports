--- src/loganalyzers/SideInfo.cc.orig	Thu Feb 26 16:55:36 2004
+++ src/loganalyzers/SideInfo.cc	Thu Feb 26 16:56:05 2004
@@ -1166,9 +1166,9 @@
 			XmlTag descr("description");
 
 			XmlTextTag<XmlParagraph> p1;
-			p1.buf() << "The 'Errors' table shows detected errors. For each
-				error type, the number of errors and their contribution towards
-				total error count are shown.";
+			p1.buf() << "The 'Errors' table shows detected errors. For each "
+				"error type, the number of errors and their contribution towards "
+				"total error count are shown.";
 			descr << p1;
 
 			blob << descr;
