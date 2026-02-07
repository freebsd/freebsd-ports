--- win/tty/termcap.c.orig	2015-11-11 10:05:22 UTC
+++ win/tty/termcap.c
@@ -206,10 +206,6 @@ int *wid, *hgt;
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
