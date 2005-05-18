--- xjtext-main.c.orig	Sat Sep  4 22:45:16 1999
+++ xjtext-main.c	Mon May 16 15:58:11 2005
@@ -9,7 +9,7 @@
   else
     {
       if(NULL==(yyin=fopen(ArgVal[1],"r")))
-	{ cerr<<form("Can't open the file named \"%s\".\n",ArgVal[1]);exit(0);}
+	{ cerr<<"Can't open the file named \"%s\".\n",ArgVal[1];exit(0);}
       strcpy(FileName,ArgVal[1]);
     }
   XWin = new xJTextWindow
