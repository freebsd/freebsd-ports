
$FreeBSD$

--- tools/clang/include/clang/Analysis/Analyses/FormatString.h.orig
+++ tools/clang/include/clang/Analysis/Analyses/FormatString.h
@@ -139,6 +139,10 @@
     SArg,
     
     // ** Printf-specific **
+
+    // FreeBSD specific specifiers
+    bArg,
+    DArg,
   
     // Objective-C specific specifiers.
     ObjCObjArg,  // '@'
