--- /usr/ports/devel/cocktail/work/cocktail-9309//./estra/m2c/ArgCheck.c	Tue Feb 15 14:23:04 1994
+++ ./estra/m2c/ArgCheck.c	Thu Aug  5 18:48:56 2004
@@ -64,7 +64,7 @@
 BOOLEAN ArgCheck_AUTO;
 BOOLEAN ArgCheck_DEBUG;
 
-static CHAR NULL [] = "/dev/null";
+static CHAR DEVNULL [] = "/dev/null";
 struct S_1 {
     CHAR A[255 + 1];
 };
@@ -188,8 +188,8 @@
     ArgCheck_IMP = TRUE;
   }
   if (!SourceFileIsOpen) {
-    Listing_SourceFile = IO_ReadOpen(NULL, 9L);
-    Checks_CheckReadOpen(&Listing_SourceFile, NULL, 9L);
+    Listing_SourceFile = IO_ReadOpen(DEVNULL, 9L);
+    Checks_CheckReadOpen(&Listing_SourceFile, DEVNULL, 9L);
   }
   if (Error) {
     Errors_CloseErrors();
