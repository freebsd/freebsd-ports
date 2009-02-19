
$FreeBSD$

--- tools/clang/lib/Sema/SemaChecking.cpp.orig
+++ tools/clang/lib/Sema/SemaChecking.cpp
@@ -643,6 +643,7 @@
     case 'G':
     case 'a':
     case 'A':
+    case 'b':
     case 'c':
     case 'C':
     case 'S':
