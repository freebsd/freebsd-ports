
$FreeBSD: /tmp/pcvs/ports/devel/clang/files/Attic/patch-tools_clang_include_clang_Analysis_Analyses_FormatString.h,v 1.1 2010-10-08 14:00:31 brooks Exp $

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
