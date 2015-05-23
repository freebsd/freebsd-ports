--- tools/clang/include/clang/Analysis/Analyses/FormatString.h.orig
+++ tools/clang/include/clang/Analysis/Analyses/FormatString.h
@@ -122,9 +122,10 @@
   enum Kind {
     InvalidSpecifier = 0,
       // C99 conversion specifiers.
+    bArg, // FreeBSD extension
     cArg,
     dArg,
-    DArg, // Apple extension
+    DArg, // Apple or FreeBSD extension
     iArg,
     IntArgBeg = dArg, IntArgEnd = iArg,
 
