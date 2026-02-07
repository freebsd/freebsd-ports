--- win/tty/termcap.c.orig	2025-03-15 15:02:36 UTC
+++ win/tty/termcap.c
@@ -195,10 +195,6 @@ term_startup(int *wid, int *hgt)
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
