--- common/unicode/unistr.h.orig	2017-03-29 04:44:37 UTC
+++ common/unicode/unistr.h
@@ -117,12 +117,20 @@ class UnicodeStringAppendable;  // unicode/appendable.
  * The string parameter must be a C string literal.
  * The length of the string, not including the terminating
  * <code>NUL</code>, must be specified as a constant.
+ * The U_STRING_DECL macro should be invoked exactly once for one
+ * such string variable before it is used.
  * @stable ICU 2.0
  */
 #if !U_CHAR16_IS_TYPEDEF
 # define UNICODE_STRING(cs, _length) icu::UnicodeString(TRUE, u ## cs, _length)
+#elif defined(U_DECLARE_UTF16)
+# define UNICODE_STRING(cs, _length) icu::UnicodeString(TRUE, (const char16_t *)U_DECLARE_UTF16(cs), _length)
+#elif U_SIZEOF_WCHAR_T==U_SIZEOF_UCHAR && (U_CHARSET_FAMILY==U_ASCII_FAMILY || (U_SIZEOF_UCHAR == 2 && defined(U_WCHAR_IS_UTF16)))
+# define UNICODE_STRING(cs, _length) icu::UnicodeString(TRUE, (const char16_t *)L ## cs, _length)
+#elif U_SIZEOF_UCHAR==1 && U_CHARSET_FAMILY==U_ASCII_FAMILY
+# define UNICODE_STRING(cs, _length) icu::UnicodeString(TRUE, (const char16_t *)cs, _length)
 #else
-# define UNICODE_STRING(cs, _length) icu::UnicodeString(TRUE, (const char16_t*)u ## cs, _length)
+# define UNICODE_STRING(cs, _length) icu::UnicodeString(cs, _length, US_INV)
 #endif
 
 /**
@@ -3985,7 +3993,7 @@ UnicodeString::isBufferWritable() const
 inline const char16_t *
 UnicodeString::getBuffer() const {
   if(fUnion.fFields.fLengthAndFlags&(kIsBogus|kOpenGetBuffer)) {
-    return nullptr;
+    return NULL;
   } else if(fUnion.fFields.fLengthAndFlags&kUsingStackBuffer) {
     return fUnion.fStackFields.fBuffer;
   } else {
