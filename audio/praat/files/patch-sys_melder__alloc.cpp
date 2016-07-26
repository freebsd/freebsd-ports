--- sys/melder_alloc.cpp.orig	2015-05-20 01:47:31 UTC
+++ sys/melder_alloc.cpp
@@ -317,8 +317,8 @@ int Melder_strcmp (const char *string1, 
 }
 
 int Melder_str32cmp (const char32 *string1, const char32 *string2) {
-	if (string1 == NULL) string1 = U"";
-	if (string2 == NULL) string2 = U"";
+	if (string1 == NULL) string1 = (char32 *)"";
+	if (string2 == NULL) string2 = (char32 *)"";
 	return str32cmp (string1, string2);
 }
 
