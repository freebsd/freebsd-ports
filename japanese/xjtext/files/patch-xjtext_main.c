--- xjtext-main.c.orig	1999-09-04 22:45:16.000000000 +0900
+++ xjtext-main.c	2012-09-11 04:23:11.000000000 +0900
@@ -3,13 +3,13 @@
 xJTextWindow*   XWin;
 
 char            FileName[256];
-main            (int ArgCnt,char** ArgVal)
+int main            (int ArgCnt,char** ArgVal)
 {
   if(ArgCnt<2){ yyin=stdin;strcpy(FileName,"stdin");}
   else
     {
       if(NULL==(yyin=fopen(ArgVal[1],"r")))
-	{ cerr<<form("Can't open the file named \"%s\".\n",ArgVal[1]);exit(0);}
+	{ cerr<<"Can't open the file named \"%s\".\n",ArgVal[1];exit(0);}
       strcpy(FileName,ArgVal[1]);
     }
   XWin = new xJTextWindow
