--- xfont.c.orig	Sat Sep  4 22:45:16 1999
+++ xfont.c	Mon May 16 15:53:22 2005
@@ -5,7 +5,7 @@
   if(NULL==TheDisplay)if(NULL==(TheDisplay=XOpenDisplay("")))
     { cerr << "Can't open display.\n";exit(1);}
   if(NULL==(KFontStruct    =XLoadQueryFont(TheDisplay,FontName)))
-    { cerr << form("Can't load font \"%s\".",FontName);exit(1);}
+    { cerr << "Can't load font \"%s\".",FontName;exit(1);}
 
   XChar2b Utsu;Utsu.byte1=0x31;Utsu.byte2=0x35;
   int CharDirection; XCharStruct CharOverAll;
@@ -152,7 +152,7 @@
   if(NULL==TheDisplay)if(NULL==(TheDisplay=XOpenDisplay("")))
     { cerr << "Can't open display.\n";exit(1);}
   if(NULL==(AFontStruct    =XLoadQueryFont(TheDisplay,FontName)))
-    { cerr << form("Can't load font \"%s\".",FontName);exit(1);}
+    { cerr << "Can't load font \"%s\".",FontName;exit(1);}
   int CharDirection; XCharStruct CharOverAll;
   XTextExtents(AFontStruct,"W",1,
 	       &CharDirection,&CharAscent,&CharDescent,&CharOverAll);
