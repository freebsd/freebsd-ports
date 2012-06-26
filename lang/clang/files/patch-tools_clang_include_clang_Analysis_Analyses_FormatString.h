
$FreeBSD: /tmp/pcvs/ports/lang/clang/files/patch-tools_clang_include_clang_Analysis_Analyses_FormatString.h,v 1.2 2012-06-26 10:10:40 fluffy Exp $

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
