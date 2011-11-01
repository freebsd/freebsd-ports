--- sl.c.orig	1998-07-22 16:01:01.000000000 +0200
+++ sl.c	2011-11-01 18:53:45.000000000 +0100
@@ -32,6 +32,11 @@
 #include <unistd.h>
 #include "sl.h"
 
+void add_man(int, int);
+int add_D51(int);
+int add_sl(int);
+void add_smoke(int,int);
+
 int ACCIDENT  = 0;
 int LOGO      = 0;
 int FLY       = 0;
@@ -59,7 +64,7 @@
     }
 }
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     int x, i;
 
@@ -85,6 +90,8 @@
     }
     mvcur(0, COLS - 1, LINES - 1, 0);
     endwin();
+
+    return 0;
 }
 
 
@@ -129,7 +136,7 @@
 }
 
 
-add_D51(int x)
+int add_D51(int x)
 {
     static char *d51[D51PATTERNS][D51HIGHT + 1]
 	= {{D51STR1, D51STR2, D51STR3, D51STR4, D51STR5, D51STR6, D51STR7,
@@ -170,7 +177,7 @@
 }
 
 
-int add_man(int y, int x)
+void add_man(int y, int x)
 {
     static char *man[2][2] = {{"", "(O)"}, {"Help!", "\\O/"}};
     int i;
@@ -181,7 +188,7 @@
 }
 
 
-int add_smoke(int y, int x)
+void add_smoke(int y, int x)
 #define SMOKEPTNS	16
 {
     static struct smokes {
