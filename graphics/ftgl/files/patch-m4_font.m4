--- m4/font.m4.orig	2019-02-07 21:39:58 UTC
+++ m4/font.m4
@@ -11,7 +11,7 @@ AC_DEFUN([FTGL_CHECK_FONT],
 AC_MSG_CHECKING(for a TrueType font on the system)
 
 dnl  First try: fontconfig
-FONT_FILE="`fc-match -sv serif 2>/dev/null| sed -ne 's/.*\file:@<:@^"@:>@*"\(@<:@^"@:>@*\)".*/\1/p' | sed q`"
+FONT_FILE="`fc-match -sv serif 2>/dev/null| sed -ne 's/.*file:@<:@^"@:>@*"\(@<:@^"@:>@*\)".*/\1/p' | sed q`"
 
 dnl  Second try: look into known paths
 if test "$FONT_FILE" = ""; then
