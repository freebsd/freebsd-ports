--- plugins/examples/index2table.cc.orig	Sun Jan 25 13:42:00 2004
+++ plugins/examples/index2table.cc	Tue Jan  2 00:15:34 2007
@@ -33,7 +33,7 @@
 
 iscalled(index2table)
 //int Editor::gettableposition(int &length, int &startpos) ;
-int Editor::startindex2table(Filter * (*func)(int fb,int sb,char *opts,ScreenPart *part=NULL)) ;
+int Editor::startindex2table(startindex2table_func_t *func) ;
 };
 #define min(x,y) ((x)<(y)?(x):(y))
 	Index2table::Index2table(int fbytes,int sbytes,int off,int len,int pbase): tableoffset(off),maxintable(len),ptrbase(pbase),Filter(fbytes,sbytes) {
