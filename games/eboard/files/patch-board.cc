
$FreeBSD$

--- board.cc.orig	Fri Jun 28 03:33:05 2002
+++ board.cc	Sat Sep 28 23:00:58 2002
@@ -626,7 +626,7 @@
   queueRepaint();
 }
 
-void Board::update(bool sndflag=false) {
+void Board::update(bool sndflag) {
   int i,j,k,rate;
   AnimatedPiece *ap;  
   Position rpv;
@@ -2005,7 +2005,7 @@
 
 // ------------- targets
 
-DropSource::DropSource(piece p, int x1,int y1,int w,int h,bool d=true) {
+DropSource::DropSource(piece p, int x1,int y1,int w,int h,bool d) {
   X=x1; Y=y1;
   X2=X+w; Y2=Y+h;
   P=p;
