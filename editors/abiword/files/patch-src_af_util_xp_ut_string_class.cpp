--- src/af/util/xp/ut_string_class.cpp.orig	Mon Jan 17 14:38:20 2005
+++ src/af/util/xp/ut_string_class.cpp	Mon Jan 17 14:38:43 2005
@@ -352,9 +352,6 @@
 #  else /* va_list is a pointer */
 #  define VA_COPY(ap1, ap2)	  ((ap1) = (ap2))
 #  endif /* va_list is a pointer */
-#  if defined (__GNUC__)
-#  define VA_COPY(ap1,ap2)     __va_copy((ap1),(ap2))
-#  endif
 #endif /* !VA_COPY */
 
 UT_String& UT_String_vprintf (UT_String & inStr, const char *format,
