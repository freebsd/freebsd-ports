
$FreeBSD$

--- global.cc.orig	Wed Jun 26 03:06:59 2002
+++ global.cc	Sat Sep 28 23:00:58 2002
@@ -260,11 +260,11 @@
     }
 }
 
-void Global::appendGame(ChessGame *cg,bool RenumberDupes=true) {
+void Global::appendGame(ChessGame *cg,bool RenumberDupes) {
   if (RenumberDupes) clearDupes(cg);
   GameList.push_back(cg);
 }
-void Global::prependGame(ChessGame *cg, bool RenumberDupes=true) {
+void Global::prependGame(ChessGame *cg, bool RenumberDupes) {
   if (RenumberDupes) clearDupes(cg);
   GameList.push_front(cg);
 }
@@ -669,7 +669,7 @@
     (*i)->setPasswordMode(pm);
 }
 
-void Global::debug(char *klass,char *method,char *data=0) {
+void Global::debug(char *klass,char *method,char *data) {
   char z[256];
   time_t now;
   string rm;
@@ -1068,7 +1068,7 @@
   panes.push_back(op);
 }
 
-void ChannelSplitter::appendToChannel(int ch,char *msg,int color,Importance im=IM_NORMAL) {
+void ChannelSplitter::appendToChannel(int ch,char *msg,int color,Importance im) {
   int i,j;
   ensurePane(ch);
   j=panes.size();
