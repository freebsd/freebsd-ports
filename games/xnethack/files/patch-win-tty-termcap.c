--- win/tty/termcap.c.orig	2021-03-22 22:28:14 UTC
+++ win/tty/termcap.c
@@ -185,10 +185,6 @@ tty_startup(int *wid, int *hgt)
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
