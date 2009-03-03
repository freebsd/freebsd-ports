
$FreeBSD$

--- tools/clang/lib/Sema/SemaChecking.cpp.orig
+++ tools/clang/lib/Sema/SemaChecking.cpp
@@ -142,7 +142,7 @@
 
   // Printf checking.
   if (const FormatAttr *Format = FDecl->getAttr<FormatAttr>()) {
-    if (Format->getType() == "printf") {
+    if (Format->getType() == "printf" || Format->getType() == "printf0") {
       bool HasVAListArg = Format->getFirstArg() == 0;
       if (!HasVAListArg) {
         if (const FunctionProtoType *Proto 
@@ -701,7 +701,6 @@
     case 'u': 
     case 'x':
     case 'X':
-    case 'D':
     case 'O':
     case 'U':
     case 'e':
@@ -717,9 +716,16 @@
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
