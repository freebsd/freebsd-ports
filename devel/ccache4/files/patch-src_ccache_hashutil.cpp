--- src/ccache/hashutil.cpp.orig	2026-10-18 11:12:58 UTC
+++ src/ccache/hashutil.cpp
@@ -167,9 +167,9 @@ check_for_incbin_directive(std::string_view str, size_
   const char* p = begin + pos + incbin_size;
   p = skip_horizontal_whitespace(p, end);
 
-  return p < end && (*p == '"' || (*p == '\\' && p + 1 < end && p[1] == '"'))
-           ? SourceCodeScan::found_incbin
-           : SourceCodeScan::none;
+  // If followed by left parenthesis it's a method call.
+  return p < end && *p == '(' ? SourceCodeScan::none
+                              : SourceCodeScan::found_incbin;
 }
 
 void
