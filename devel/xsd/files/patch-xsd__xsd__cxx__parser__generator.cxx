clang build fixes: WideString is needed due to the use of wchar_t in lots of
places.
--- xsd/xsd/cxx/parser/generator.cxx~	2012-08-10 15:00:10.000000000 -0300
+++ xsd/xsd/cxx/parser/generator.cxx	2012-08-10 15:00:14.000000000 -0300
@@ -712,8 +712,8 @@
 
         // String-based types.
         //
-        String char_type (ops.value<CLI::char_type> ());
-        String string_type;
+        WideString char_type (ops.value<CLI::char_type> ());
+        WideString string_type;
 
         if (char_type == L"char")
           string_type = L"::std::string";
@@ -722,13 +722,13 @@
         else
           string_type = L"::std::basic_string< " + char_type + L" >";
 
-        String xns;
+        WideString xns;
         {
           Context ctx (std::wcerr, schema, file_path, ops, 0, 0, 0, 0);
           xns = ctx.xs_ns_name ();
         }
 
-        String buffer (L"::std::auto_ptr< " + xns + L"::buffer >");
+        WideString buffer (L"::std::auto_ptr< " + xns + L"::buffer >");
         TypeMap::Namespace xsd ("http://www\\.w3\\.org/2001/XMLSchema");
 
         xsd.types_push_back ("string", string_type);
@@ -1243,7 +1243,7 @@
 
         Indentation::Clip<Indentation::SLOC, WideChar> hxx_sloc (hxx);
 
-        String guard (guard_expr.merge (guard_prefix + hxx_name));
+        WideString guard (guard_expr.merge (guard_prefix + hxx_name));
         guard = ctx.escape (guard); // Make it a C++ id.
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
@@ -1469,7 +1469,7 @@
                      &ixx_expr,
                      &hxx_impl_expr);
 
-        String guard (guard_expr.merge (guard_prefix + hxx_impl_name));
+        WideString guard (guard_expr.merge (guard_prefix + hxx_impl_name));
         guard = ctx.escape (guard); // Make it a C++ id.
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 

