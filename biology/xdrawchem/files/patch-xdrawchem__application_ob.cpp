--- ./xdrawchem/application_ob.cpp.orig	2005-11-30 03:47:14.000000000 +0000
+++ ./xdrawchem/application_ob.cpp	2012-10-30 14:37:35.092762310 +0000
@@ -87,7 +87,7 @@
   OBFormat *inFormat = NULL;
 
   if (infilter.left(2) == "--") {
-    inFormat = Conv.FormatFromExt(infile);
+    inFormat = Conv.FormatFromExt(infile.ascii());
     if (inFormat == NULL) {
       QMessageBox::warning( 0, tr("Could not determine file type"),
 			    tr("Please select a file type from the list.") );
