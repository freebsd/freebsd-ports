--- src/window.c.orig	2021-01-01 17:45:55 UTC
+++ src/window.c
@@ -66,6 +66,7 @@ static const char *CE, *Al, *Dl, *AL, *DL;
 static const char *CS, *SF, *SR, *VB, *BL;
 static const char *VE, *VI, *KS, *KE;
 static const char *CD, *CL, *IC, *DC;
+static char *mcBC;
 static const char *CR, *NL;
 #ifdef ST_LINE
 static const char *TS, *FS, *DS;
@@ -320,8 +321,8 @@ static void _gotoxy(int x, int y)
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
@@ -1950,7 +1951,7 @@ int win_init(int fg, int bg, int attr)
   CL = tgetstr("cl", &_tptr);
   IC = tgetstr("ic", &_tptr);
   DC = tgetstr("dc", &_tptr);
-  BC = tgetstr("bc", &_tptr);
+  mcBC = tgetstr("bc", &_tptr);
   CR = tgetstr("cr", &_tptr);
   NL = tgetstr("nl", &_tptr);
   AC = tgetstr("ac", &_tptr);
@@ -2009,11 +2010,11 @@ int win_init(int fg, int bg, int attr)
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
