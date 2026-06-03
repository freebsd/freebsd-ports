--- src/Library/Color/Color.h.orig	2025-09-07 22:10:00 UTC
+++ src/Library/Color/Color.h
@@ -104,7 +104,7 @@ struct fmt::formatter<ColorTag> {
         auto pos = ctx.begin();
         auto end = ctx.end();
         if (pos == end || *pos != ':' || ++pos == end || *pos != '}')
-            fmt::detail::throw_format_error("ColorTag needs {::} format specifier");
+            fmt::report_error("ColorTag needs {::} format specifier");
         return pos; // pos points to '}'
     }
 
