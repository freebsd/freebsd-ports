--- pdf2djvu.cc.orig	2022-04-07 16:02:35 UTC
+++ pdf2djvu.cc
@@ -89,7 +89,8 @@ static int get_page_for_goto_link(pdf::link::GoTo *got
 #endif
   }
   else
-    dest.reset(orig_dest->copy());
+    // https://github.com/jwilk/pdf2djvu/commit/81b635e014ebd0240a8719cc39b6a1b759cc6a98
+    dest.reset(new pdf::link::Destination(*orig_dest));
   if (dest.get() != nullptr)
   {
     int page;
