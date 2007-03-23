--- hack/hack.termcap.c.orig	Sat Mar  6 22:18:53 2004
+++ hack/hack.termcap.c	Thu Mar 11 18:42:47 2004
@@ -35,7 +35,8 @@
 		flags.nonull = 1;
 	if(pc = tgetstr("pc", &tbufptr))
 		PC = *pc;
-	if(!(BC = tgetstr("bc", &tbufptr))) {
+	if(!(BC = tgetstr("bc", &tbufptr))
+	 &&!(BC = tgetstr("le", &tbufptr))) {
 		if(!tgetflag("bs"))
 			error("Terminal must backspace.");
 		BC = tbufptr;

