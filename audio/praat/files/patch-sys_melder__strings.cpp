--- sys/melder_strings.cpp.orig	2015-05-20 01:47:31 UTC
+++ sys/melder_strings.cpp
@@ -386,7 +386,7 @@ void MelderString32_appendCharacter (Mel
 	expandIfNecessary (char32)
 	my string [my length] = character;
 	my length ++;
-	my string [my length] = U'\0';
+	my string [my length] = (char32)'\0';
 }
 
 void MelderString_get (MelderString *me, wchar_t *destination) {
