
$FreeBSD$

--- tools/clang/include/clang/Analysis/Analyses/FormatString.h.orig
+++ tools/clang/include/clang/Analysis/Analyses/FormatString.h
@@ -143,6 +143,10 @@
 
     // ** Printf-specific **
 
+    // FreeBSD specific specifiers
+    bArg,
+    DArg,
+
     // Objective-C specific specifiers.
     ObjCObjArg,  // '@'
     ObjCBeg = ObjCObjArg, ObjCEnd = ObjCObjArg,
