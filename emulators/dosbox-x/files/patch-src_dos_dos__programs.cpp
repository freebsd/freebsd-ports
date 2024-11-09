Fix build with clang 19
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282386

--- src/dos/dos_programs.cpp.orig	2024-10-02 06:16:36 UTC
+++ src/dos/dos_programs.cpp
@@ -81,7 +81,7 @@ host_cnv_char_t *CodePageGuestToHost(const char *s);
 #endif
 #ifdef C_ICONV
 #include "iconvpp.hpp"
-typedef uint16_t test_char_t;
+typedef char16_t test_char_t;
 typedef std::basic_string<test_char_t> test_string;
 typedef std::basic_string<char> test_char;
 #endif
@@ -102,6 +102,9 @@ bool CodePageHostToGuestUTF8(char *d/*CROSS_LEN*/,cons
 bool qmount = false;
 bool nowarn = false;
 bool CodePageHostToGuestUTF8(char *d/*CROSS_LEN*/,const char *s/*CROSS_LEN*/), CodePageHostToGuestUTF16(char *d/*CROSS_LEN*/,const uint16_t *s/*CROSS_LEN*/);
+inline bool CodePageHostToGuestUTF16(char *d/*CROSS_LEN*/,const char16_t *s/*CROSS_LEN*/) {
+    return CodePageHostToGuestUTF16(d, reinterpret_cast<const uint16_t *>(s));
+}
 extern bool systemmessagebox(char const * aTitle, char const * aMessage, char const * aDialogType, char const * aIconType, int aDefaultButton);
 extern bool addovl, addipx, addne2k, prepared, inshell, usecon, uao, loadlang, morelen, mountfro[26], mountiro[26], resetcolor, staycolors, printfont, notrycp, internal_program;
 extern bool clear_screen(), OpenGL_using(void), DOS_SetAnsiAttr(uint8_t attr), isDBCSCP();
