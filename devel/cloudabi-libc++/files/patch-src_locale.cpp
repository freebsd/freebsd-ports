--- src/locale.cpp.orig	2015-06-24 08:46:54 UTC
+++ src/locale.cpp
@@ -575,8 +575,6 @@ locale::global(const locale& loc)
     locale& g = __global();
     locale r = g;
     g = loc;
-    if (g.name() != "*")
-        setlocale(LC_ALL, g.name().c_str());
     return r;
 }
 
@@ -813,7 +811,7 @@ ctype<wchar_t>::do_toupper(char_type c) 
 #elif defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__NetBSD__)
     return isascii(c) ? ctype<char>::__classic_upper_table()[c] : c;
 #else
-    return (isascii(c) && iswlower_l(c, __cloc())) ? c-L'a'+L'A' : c;
+    return (isascii(c) && iswlower(c)) ? c-L'a'+L'A' : c;
 #endif
 }
 
@@ -827,7 +825,7 @@ ctype<wchar_t>::do_toupper(char_type* lo
         *low = isascii(*low) ? ctype<char>::__classic_upper_table()[*low]
                              : *low;
 #else
-        *low = (isascii(*low) && islower_l(*low, __cloc())) ? (*low-L'a'+L'A') : *low;
+        *low = (isascii(*low) && islower(*low)) ? (*low-L'a'+L'A') : *low;
 #endif
     return low;
 }
@@ -840,7 +838,7 @@ ctype<wchar_t>::do_tolower(char_type c) 
 #elif defined(__GLIBC__) || defined(__EMSCRIPTEN__) || defined(__NetBSD__)
     return isascii(c) ? ctype<char>::__classic_lower_table()[c] : c;
 #else
-    return (isascii(c) && isupper_l(c, __cloc())) ? c-L'A'+'a' : c;
+    return (isascii(c) && isupper(c)) ? c-L'A'+'a' : c;
 #endif
 }
 
@@ -854,7 +852,7 @@ ctype<wchar_t>::do_tolower(char_type* lo
         *low = isascii(*low) ? ctype<char>::__classic_lower_table()[*low]
                              : *low;
 #else
-        *low = (isascii(*low) && isupper_l(*low, __cloc())) ? *low-L'A'+L'a' : *low;
+        *low = (isascii(*low) && isupper(*low)) ? *low-L'A'+L'a' : *low;
 #endif
     return low;
 }
@@ -923,7 +921,7 @@ ctype<char>::do_toupper(char_type c) con
     return isascii(c) ? 
       static_cast<char>(__classic_upper_table()[static_cast<unsigned char>(c)]) : c;
 #else
-    return (isascii(c) && islower_l(c, __cloc())) ? c-'a'+'A' : c;
+    return (isascii(c) && islower(c)) ? c-'a'+'A' : c;
 #endif
 }
 
@@ -940,7 +938,7 @@ ctype<char>::do_toupper(char_type* low, 
         *low = isascii(*low) ?
           static_cast<char>(__classic_upper_table()[static_cast<size_t>(*low)]) : *low;
 #else
-        *low = (isascii(*low) && islower_l(*low, __cloc())) ? *low-'a'+'A' : *low;
+        *low = (isascii(*low) && islower(*low)) ? *low-'a'+'A' : *low;
 #endif
     return low;
 }
@@ -957,7 +955,7 @@ ctype<char>::do_tolower(char_type c) con
     return isascii(c) ?
       static_cast<char>(__classic_lower_table()[static_cast<size_t>(c)]) : c;
 #else
-    return (isascii(c) && isupper_l(c, __cloc())) ? c-'A'+'a' : c;
+    return (isascii(c) && isupper(c)) ? c-'A'+'a' : c;
 #endif
 }
 
@@ -972,7 +970,7 @@ ctype<char>::do_tolower(char_type* low, 
 #elif defined(__GLIBC__) || defined(__EMSCRIPTEN__)
         *low = isascii(*low) ? static_cast<char>(__classic_lower_table()[static_cast<size_t>(*low)]) : *low;
 #else
-        *low = (isascii(*low) && isupper_l(*low, __cloc())) ? *low-'A'+'a' : *low;
+        *low = (isascii(*low) && isupper(*low)) ? *low-'A'+'a' : *low;
 #endif
     return low;
 }
@@ -1201,28 +1199,28 @@ ctype_byname<char>::~ctype_byname()
 char
 ctype_byname<char>::do_toupper(char_type c) const
 {
-    return static_cast<char>(toupper_l(static_cast<unsigned char>(c), __l));
+    return static_cast<char>(toupper(static_cast<unsigned char>(c)));
 }
 
 const char*
 ctype_byname<char>::do_toupper(char_type* low, const char_type* high) const
 {
     for (; low != high; ++low)
-        *low = static_cast<char>(toupper_l(static_cast<unsigned char>(*low), __l));
+        *low = static_cast<char>(toupper(static_cast<unsigned char>(*low)));
     return low;
 }
 
 char
 ctype_byname<char>::do_tolower(char_type c) const
 {
-    return static_cast<char>(tolower_l(static_cast<unsigned char>(c), __l));
+    return static_cast<char>(tolower(static_cast<unsigned char>(c)));
 }
 
 const char*
 ctype_byname<char>::do_tolower(char_type* low, const char_type* high) const
 {
     for (; low != high; ++low)
-        *low = static_cast<char>(tolower_l(static_cast<unsigned char>(*low), __l));
+        *low = static_cast<char>(tolower(static_cast<unsigned char>(*low)));
     return low;
 }
 
@@ -1707,11 +1705,6 @@ codecvt<wchar_t, char, mbstate_t>::do_un
 int
 codecvt<wchar_t, char, mbstate_t>::do_encoding() const  _NOEXCEPT
 {
-#ifdef _LIBCPP_LOCALE__L_EXTENSIONS
-    if (mbtowc_l(nullptr, nullptr, MB_LEN_MAX, __l) == 0)
-#else
-    if (__mbtowc_l(nullptr, nullptr, MB_LEN_MAX, __l) == 0)
-#endif
     {
         // stateless encoding
 #ifdef _LIBCPP_LOCALE__L_EXTENSIONS
