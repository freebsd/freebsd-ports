--- src/tool/omniidl/cxx/idlutil.cc.orig	Thu Jul 25 16:49:13 2002
+++ src/tool/omniidl/cxx/idlutil.cc	Thu Jul 25 16:49:25 2002
@@ -139,13 +139,13 @@
   IdlIntLiteral ull;
   switch (base) {
   case 8:
-    sscanf(text, "%I64o", &ull);
+    sscanf(text, "%qo", &ull);
     break;
   case 10:
-    sscanf(text, "%I64d", &ull);
+    sscanf(text, "%qd", &ull);
     break;
   case 16:
-    sscanf(text, "%I64x", &ull);
+    sscanf(text, "%qx", &ull);
     break;
   default:
     abort();
