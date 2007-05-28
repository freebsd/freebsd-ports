--- hack/hack.termcap.c.orig	Tue Nov 16 11:26:38 1999
+++ hack/hack.termcap.c	Sun May 27 21:39:48 2007
@@ -11,10 +11,11 @@
 extern long *alloc();
 
 static char tbuf[512];
-static char *HO, *CL, *CE, *UP, *CM, *ND, *XD, *BC, *SO, *SE, *TI, *TE;
+static char *HO, *CL, *CE, *CM, *ND, *XD, *SO, *SE, *TI, *TE;
+char *UP, *BC;
 static char *VS, *VE;
 static int SG;
-static char PC = '\0';
+char PC = '\0';
 char *CD;		/* tested in pri.c: docorner() */
 int CO, LI;		/* used in pri.c and whatis.c */
 
@@ -35,7 +36,8 @@ startup()
 		flags.nonull = 1;
 	if(pc = tgetstr("pc", &tbufptr))
 		PC = *pc;
-	if(!(BC = tgetstr("bc", &tbufptr))) {
+	if(!(BC = tgetstr("bc", &tbufptr))
+	 &&!(BC = tgetstr("le", &tbufptr))) {
 		if(!tgetflag("bs"))
 			error("Terminal must backspace.");
 		BC = tbufptr;
