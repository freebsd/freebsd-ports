--- src/tool/omniidl/cxx/idlutil.cc.orig	2013-07-18 11:28:03 UTC
+++ src/tool/omniidl/cxx/idlutil.cc
@@ -108,13 +108,13 @@ idl_strtoul(const char* text, int base)
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
