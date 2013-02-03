clang build fixes: WideString is needed due to the use of wchar_t in lots of
places.
--- xsd/xsd/cxx/tree/generator.cxx~	2012-08-10 15:37:22.000000000 -0300
+++ xsd/xsd/cxx/tree/generator.cxx	2012-08-10 15:37:46.000000000 -0300
@@ -1304,7 +1304,7 @@
 
         // Guard
         //
-        String guard (guard_expr.merge (guard_prefix + fwd_name));
+        WideString guard (guard_expr.merge (guard_prefix + fwd_name));
         guard = ctx.escape (guard); // make a c++ id
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
@@ -1420,7 +1420,7 @@
 
         // Guard
         //
-        String guard (guard_expr.merge (guard_prefix + hxx_name));
+        WideString guard (guard_expr.merge (guard_prefix + hxx_name));
         guard = ctx.escape (guard); // make a c++ id
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);

@@ -1575,7 +1575,7 @@
 
         // Guard
         //
-        String guard (guard_expr.merge (guard_prefix + ixx_name));
+        WideString guard (guard_expr.merge (guard_prefix + ixx_name));
         guard = ctx.escape (guard); // make a c++ id
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
 
