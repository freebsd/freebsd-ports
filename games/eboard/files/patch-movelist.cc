
$FreeBSD$

--- movelist.cc.orig	Sun Apr 28 23:04:34 2002
+++ movelist.cc	Sat Sep 28 23:00:58 2002
@@ -95,8 +95,8 @@
 }
 
 void MoveListWindow::updateList(list<Position> &moves,
-				int over=0,GameResult result=UNDEF,
-				char *reason=0) {
+				int over,GameResult result,
+				char *reason) {
   populate_clist(moves,over,result,reason);
 }
 
