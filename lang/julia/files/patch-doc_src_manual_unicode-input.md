--- doc/src/manual/unicode-input.md.orig	2024-05-10 00:16:25 UTC
+++ doc/src/manual/unicode-input.md
@@ -70,7 +70,7 @@ function table_entries(completions, unicode_dict)
             join(inputs, ", "), join(unicode_names, " + ")
         ])
     end
-    return Markdown.Table(entries, [:l, :l, :l, :l])
+    return Markdown.MD(entries, [:l, :l, :l, :l])
 end
 
 table_entries(
