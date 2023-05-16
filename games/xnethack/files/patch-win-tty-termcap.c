--- win/tty/termcap.c.orig	2023-05-16 21:33:58 UTC
+++ win/tty/termcap.c
@@ -192,10 +192,6 @@ tty_startup(int *wid, int *hgt)
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
