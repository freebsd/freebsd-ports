--- win/tty/termcap.c.orig	2022-03-07 23:57:15 UTC
+++ win/tty/termcap.c
@@ -188,10 +188,6 @@ tty_startup(int *wid, int *hgt)
         error("Terminal must backspace.");
 #else
         if (!(BC = Tgetstr("bc"))) { /* termcap also uses bc/bs */
-#ifndef MINIMAL_TERM
-            if (!tgetflag("bs"))
-                error("Terminal must backspace.");
-#endif
             BC = tbufptr;
             tbufptr += 2;
             *BC = '\b';
