--- src/mainwindow.cpp.orig	2006-01-13 12:56:45.000000000 +0300
+++ src/mainwindow.cpp	2009-03-17 20:10:37.000000000 +0300
@@ -123,7 +123,7 @@
   // Load a RFC number
   bool bOK;
   int iRFCNum = QInputDialog::getInteger(this, tr("Please enter a RFC number"),
-                                             tr("RFC#:"), 0, 1, 5000, 1, &bOK);
+                                             tr("RFC#:"), 0, 1, 100000, 1, &bOK);
   if (bOK)
     RFCLoad( iRFCNum );
 }
