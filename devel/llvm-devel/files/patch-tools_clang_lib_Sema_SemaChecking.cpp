
$FreeBSD$

--- tools/clang/lib/Sema/SemaChecking.cpp.orig
+++ tools/clang/lib/Sema/SemaChecking.cpp
@@ -699,7 +699,6 @@
     case 'u': 
     case 'x':
     case 'X':
-    case 'D':
     case 'O':
     case 'U':
     case 'e':
@@ -715,9 +714,16 @@
     case 'S':
     case 's':
     case 'p': 
+    case 'r':
+    case 'y':
       ++numConversions;
       CurrentState = state_OrdChr;
       break;
+    case 'b':
+    case 'D':
+      numConversions += 2;
+      CurrentState = state_OrdChr;
+      break;
 
     // CHECK: Are we using "%n"?  Issue a warning.
     case 'n': {
