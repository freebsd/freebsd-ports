--- plugins/examples/elftables.cc.orig	Thu May 23 16:28:24 2002
+++ plugins/examples/elftables.cc	Tue Jan  2 00:16:12 2007
@@ -43,7 +43,7 @@
 class Editor {
 public:
 #include "faked.h"
-int Editor::startindex2table(Filter * (*func)(int fb,int sb,char *opts,ScreenPart *part=NULL)) ;
+int Editor::startindex2table(startindex2table_func_t *func) ;
 int Editor::getanswer(const char *question,char *answ,int anslen,int ansroom=5);
 
 int Editor::getsymposition(int &length, int &startpos) ;
