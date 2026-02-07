--- modules/javafx.web/src/main/native/Source/WTF/wtf/unicode/java/UnicodeJava.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/unicode/java/UnicodeJava.h
@@ -37,21 +37,6 @@
 
 #define CharProp(p) com_sun_webkit_dom_CharacterDataImpl_##p
 
-#if PLATFORM(JAVA) && OS(WINDOWS)
-typedef wchar_t UChar;
-#else
-typedef uint16_t UChar;
-#endif
-
-// #ifdef UChar32
-// #undef UChar32
-// #endif
-
-#ifndef __UMACHINE_H__ //XXX: recheck
-typedef uint32_t UChar32;
-#endif
-
-#define U_MASK(x) ((uint32_t)1<<(x))
 #define USE_FAST_PATH(c, fast, slow) ((c) <= 0x7F ? fast((char)c) : slow(c))
 
 #define CHECK_PROPERTY(c, mask, isSet) \
