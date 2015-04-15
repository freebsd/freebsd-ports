--- src/locale.cpp.orig	2014-01-04 17:43:00 UTC
+++ src/locale.cpp
@@ -1021,7 +1021,7 @@ extern "C" const int ** __ctype_toupper_
 const ctype<char>::mask*
 ctype<char>::classic_table()  _NOEXCEPT
 {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
     return _DefaultRuneLocale.__runetype;
 #elif defined(__NetBSD__)
     return _C_ctype_tab_ + 1;
