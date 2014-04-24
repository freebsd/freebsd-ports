--- sl.c.orig	2014-01-04 00:18:33.000000000 -0500
+++ sl.c	2014-03-16 16:16:47.000000000 -0400
@@ -37,6 +37,12 @@
 #include <unistd.h>
 #include "sl.h"
 
+int add_sl(int);
+int add_C51(int);
+int add_D51(int);
+void add_man(int, int);
+void add_smoke(int, int);
+
 int ACCIDENT  = 0;
 int LOGO      = 0;
 int FLY       = 0;
@@ -99,6 +105,8 @@
     }
     mvcur(0, COLS - 1, LINES - 1, 0);
     endwin();
+
+    return 0;
 }
 
 
@@ -143,7 +151,7 @@
 }
 
 
-add_D51(int x)
+int add_D51(int x)
 {
     static char *d51[D51PATTERNS][D51HIGHT + 1]
 	= {{D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
@@ -183,7 +191,7 @@
     return OK;
 }
 
-add_C51(int x)
+int add_C51(int x)
 {
     static char *c51[C51PATTERNS][C51HIGHT + 1]
 	= {{C51STR1, C51STR2, C51STR3, C51STR4, C51STR5, C51STR6, C51STR7,
@@ -224,7 +232,7 @@
 }
 
 
-int add_man(int y, int x)
+void add_man(int y, int x)
 {
     static char *man[2][2] = {{"", "(O)"}, {"Help!", "\\O/"}};
     int i;
@@ -235,7 +243,7 @@
 }
 
 
-int add_smoke(int y, int x)
+void add_smoke(int y, int x)
 #define SMOKEPTNS	16
 {
     static struct smokes {
