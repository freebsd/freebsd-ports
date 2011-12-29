--- src/window.c.orig	2010-12-12 14:56:25.000000000 +0100
+++ src/window.c	2011-12-28 16:07:59.000000000 +0100
@@ -66,6 +66,7 @@ static const char *CE, *Al, *Dl, *AL, *D
 static const char *CS, *SF, *SR, *VB, *BL;
 static const char *VE, *VI, *KS, *KE;
 static const char *CD, *CL, *IC, *DC;
+static char *mcBC;
 static const char *CR, *NL;
 #ifdef ST_LINE
 static const char *TS, *FS, *DS;
@@ -335,8 +336,8 @@ static void _gotoxy(int x, int y)
   else if (NL != NULL && x == 0 && x == curx && y == cury + 1)
     outstr(NL);
 #endif
-  else if (BC != NULL && y == cury && x == curx - 1)
-    outstr(BC);
+  else if (mcBC != NULL && y == cury && x == curx - 1)
+    outstr(mcBC);
   else
     outstr(tgoto(CM, x, y));
   curx = x;
@@ -2000,7 +2001,7 @@ int win_init(int fg, int bg, int attr)
   CL = tgetstr("cl", &_tptr);
   IC = tgetstr("ic", &_tptr);
   DC = tgetstr("dc", &_tptr);
-  BC = tgetstr("bc", &_tptr);
+  mcBC = tgetstr("bc", &_tptr);
   CR = tgetstr("cr", &_tptr);
   NL = tgetstr("nl", &_tptr);
   AC = tgetstr("ac", &_tptr);
@@ -2059,11 +2060,11 @@ int win_init(int fg, int bg, int attr)
   _has_am = tgetflag("am");
   _mv_standout = tgetflag("ms");
   if (tgetflag("bs")) {
-    if (BC == NULL)
-      BC = "\b";
+    if (mcBC == NULL)
+      mcBC = "\b";
   }
   else
-    BC = NULL;
+    mcBC = NULL;
 
   /* Special IBM box-drawing characters */
   D_UL  = 201;
