--- PRImageView.m.orig	2007-12-08 01:32:13.000000000 +0100
+++ PRImageView.m	2008-02-21 15:18:34.000000000 +0100
@@ -81,12 +81,13 @@
 }
 
 
+#if 0
 - (NSRect ) rectForPage: (int) pageNumber
 {
     NSPrintInfo *pi = [[[NSDocumentController sharedDocumentController] currentDocument] printInfo];
     return [pi imageablePageBounds];
 }
-
+#endif
 
 
 -(void) dealloc
