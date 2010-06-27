
--- layoutex/ParagraphLayout.bak	2009-10-15 21:21:15.000000000 +0200
+++ layoutex/ParagraphLayout.cpp	2009-10-15 21:22:44.000000000 +0200
@@ -813,7 +813,7 @@
 
     return nullLanguageCode;
 }
-#elif
+#else
 
 // TODO - dummy implementation for right now...
 le_int32 ParagraphLayout::getLanguageCode(const Locale *locale)


