
$FreeBSD$

--- win/tty/termcap.c.orig	Thu Jun 19 16:12:47 2003
+++ win/tty/termcap.c	Thu Jun 19 16:13:00 2003
@@ -217,10 +217,6 @@
 	    error("Terminal must backspace.");
 # else
 	    if(!(BC = Tgetstr("bc"))) {	/* termcap also uses bc/bs */
-#  ifndef MINIMAL_TERM
-		if(!tgetflag("bs"))
-			error("Terminal must backspace.");
-#  endif
 		BC = tbufptr;
 		tbufptr += 2;
 		*BC = '\b';
