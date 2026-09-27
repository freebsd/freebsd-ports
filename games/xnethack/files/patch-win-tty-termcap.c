--- win/tty/termcap.c.orig	2026-05-27 00:15:32 UTC
+++ win/tty/termcap.c
@@ -200,10 +200,6 @@ term_startup(int *wid, int *hgt)
         error("Terminal must backspace.");
 #else
         if (!(BC = Tgetstr(nhStr("bc")))) { /* termcap also uses bc/bs */
-#ifndef MINIMAL_TERM
-            if (!tgetflag(nhStr("bs")))
-                error("Terminal must backspace.");
-#endif
             BC = tbufptr;
             tbufptr += 2;
             *BC = '\b';
