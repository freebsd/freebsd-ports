
$FreeBSD$

--- tools/clang/include/clang/Analysis/Analyses/FormatString.h.orig
+++ tools/clang/include/clang/Analysis/Analyses/FormatString.h
@@ -141,6 +141,10 @@
     SArg,
 
     // ** Printf-specific **
+    
+    // FreeBSD specific specifiers
+    bArg,
+    DArg,
 
     // Objective-C specific specifiers.
     ObjCObjArg,  // '@'
