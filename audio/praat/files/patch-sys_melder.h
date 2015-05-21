--- sys/melder.h.orig	2015-03-22 17:29:26 UTC
+++ sys/melder.h
@@ -51,6 +51,8 @@
 	#define INT54_MIN  -9007199254740991LL
 #endif
 
+#include <uchar.h>
+
 typedef wchar_t wchar;
 typedef uint8_t  char8_t;
 typedef char32_t char32;
@@ -222,7 +224,7 @@ static inline int64_t str16len (const ch
 		return (int64_t) wcslen ((const wchar_t *) string);
 	} else {
 		int64_t result = 0;
-		while (* string ++ != u'\0') result ++;
+		while (* string ++ != (char16_t)'\0') result ++;
 		return result;
 	}
 }
@@ -230,8 +232,8 @@ static inline void str16cpy (char16_t *t
 	if (sizeof (wchar_t) == 2) {
 		wcscpy ((wchar_t *) target, (const wchar_t *) source);
 	} else {
-		while (* source != u'\0') * target ++ = * source ++;
-		* target = u'\0';
+		while (* source != (char16_t)'\0') * target ++ = * source ++;
+		* target = (char16_t)'\0';
 	}
 }
 static inline int str16cmp (const char16_t *string1, const char16_t *string2) {
@@ -239,7 +241,7 @@ static inline int str16cmp (const char16
 		return wcscmp ((const wchar_t *) string1, (const wchar_t *) string2);
 	} else {
 		while (*string1 == *string2 ++) {
-			if (*string1 ++ == u'\0') {
+			if (*string1 ++ == (char16_t)'\0') {
 				return 0;
 			}
 		}
@@ -251,7 +253,7 @@ static inline int64_t str32len (const ch
 		return (int64_t) wcslen ((const wchar_t *) string);
 	} else {
 		int64_t result = 0;
-		while (* string ++ != U'\0') result ++;
+		while (* string ++ != (char32_t)'\0') result ++;
 		return result;
 	}
 }
@@ -259,8 +261,8 @@ static inline void str32cpy (char32_t *t
 	if (sizeof (wchar_t) == 4) {
 		wcscpy ((wchar_t *) target, (const wchar_t *) source);
 	} else {
-		while (* source != U'\0') * target ++ = * source ++;
-		* target = U'\0';
+		while (* source != (char32_t)'\0') * target ++ = * source ++;
+		* target = (char32_t)'\0';
 	}
 }
 static inline int str32cmp (const char32_t *string1, const char32_t *string2) {
@@ -268,7 +270,7 @@ static inline int str32cmp (const char32
 		return wcscmp ((const wchar_t *) string1, (const wchar_t *) string2);
 	} else {
 		while (*string1 == *string2 ++) {
-			if (*string1 ++ == U'\0') {
+			if (*string1 ++ == (char32_t)'\0') {
 				return 0;
 			}
 		}
@@ -1171,6 +1173,11 @@ public:
 			Melder_fclose (file, tmp);
 		}
 	}
+	// operator () is not working in Sound_files.cpp:226 for some reason
+	FILE * get_ptr(void)
+	{
+	        return ptr;
+	}
 };
 
 class autoMelderFile {
