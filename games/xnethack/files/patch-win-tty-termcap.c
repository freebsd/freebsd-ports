--- win/tty/termcap.c.orig	2026-02-28 22:45:03 UTC
+++ win/tty/termcap.c
@@ -196,10 +196,6 @@ term_startup(int *wid, int *hgt)
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
