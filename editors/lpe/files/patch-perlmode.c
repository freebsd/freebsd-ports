--- src/modes/perlmode.c.orig	Sun Dec  9 16:54:40 2001
+++ src/modes/perlmode.c	Sun Dec  9 16:54:56 2001
@@ -156,7 +156,7 @@
     mode_util_set_slang_color ( "cmode", "illegal", COLOR_ILLEGAL, COLOR_ILLEGAL_FG, COLOR_ILLEGAL_BG );
     mode_util_set_slang_color ( "cmode", "debug", COLOR_DEBUG, COLOR_DEBUG_FG, COLOR_DEBUG_BG );
     mode_util_set_slang_color ( "perlmode", "variable", COLOR_VARIABLE, "brightcyan", "black" );
-    mode_util_set_slang_color ( "perlmode", "shell", COLOR_SHELL, "magneta", "black" );
+    mode_util_set_slang_color ( "perlmode", "shell", COLOR_SHELL, "magenta", "black" );
 #ifdef HIGHLIGHT_REGEXPS
-    mode_util_set_slang_color ( "perlmode", "regexp", COLOR_REGEXP, "magneta", "black" );
+    mode_util_set_slang_color ( "perlmode", "regexp", COLOR_REGEXP, "magenta", "black" );
 #endif /* HIGHLIGHT_REGEXPS */
