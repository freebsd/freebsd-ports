--- source/astub.c.orig	Sat Aug 21 16:45:37 2004
+++ source/astub.c	Sat Aug 21 16:52:30 2004
@@ -134,6 +134,9 @@
     };
 extern char buildkeys[NUMKEYS];
 
+void PrintStatus(char *string,int num,char x,char y,char color);
+void SpriteName(short spritenum, char *lo2);
+void Ver();
 
 
 
