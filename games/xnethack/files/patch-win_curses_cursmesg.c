--- win/curses/cursmesg.c.orig	2025-03-17 13:33:30 UTC
+++ win/curses/cursmesg.c
@@ -31,7 +31,7 @@ glyph_info mesg_gi;
 glyph_info mesg_gi;
 
 #ifndef CURSES_GENL_PUTMIXED
-#if defined(PDC_WIDE) || defined(NCURSES_WIDECHAR)
+#if defined(PDC_WIDE) || NCURSES_WIDECHAR
 #define USE_CURSES_PUTMIXED
 #else  /* WIDE */
 #ifdef NH_PRAGMA_MESSAGE
