
$FreeBSD$

--- position.cc.orig	Fri Jun 14 19:32:57 2002
+++ position.cc	Sat Sep 28 23:00:58 2002
@@ -257,7 +257,7 @@
   return(LastMove);
 }
 
-void Position::moveAnyNotation(char *m,piece color,variant Vr=REGULAR) {
+void Position::moveAnyNotation(char *m,piece color,variant Vr) {
   int i,x,y,ml;
   piece pr;
   char xlate[12];
@@ -317,7 +317,7 @@
     }
 }
 
-void Position::moveStdNotation(char *m,piece color,variant Vr=REGULAR) {
+void Position::moveStdNotation(char *m,piece color,variant Vr) {
   int from[2],to[2];
   int istake, isdrop;
   piece what, prom;
@@ -449,7 +449,7 @@
 }
 
 void Position::locate(piece p,int *src,int *dest,int istake,
-		      variant Vr=REGULAR) {
+		      variant Vr) {
   int minx,maxx,miny,maxy;
   int i,j,dc,dr,m,n;
   piece kind,color;
@@ -563,8 +563,8 @@
 }
 
 void Position::moveCartesian(int x1,int y1,int x2,int y2,
-			     variant Vr=REGULAR, 
-			     bool resolvepromotion=false)
+			     variant Vr,
+			     bool resolvepromotion)
 {
   piece color;
 
@@ -664,7 +664,7 @@
   stdNotationForMove(x1,y1,x2,y2,prom,dest);
 }
 
-void Position::stdNotationForMove(int x1,int y1,int x2,int y2,piece prom,char *m,variant Vr=REGULAR) {
+void Position::stdNotationForMove(int x1,int y1,int x2,int y2,piece prom,char *m,variant Vr) {
   Position after;
   stdNotationForMoveInternal(x1,y1,x2,y2,m);
   switch(prom) {
@@ -1003,7 +1003,7 @@
   return(HouseString);
 }
 
-string & Position::getMaterialString(variant Vr=REGULAR) {
+string & Position::getMaterialString(variant Vr) {
   int w=0,b=0,i,j,v;
   char tmp[64];
 
@@ -1179,7 +1179,7 @@
 }
 
 // dc = defender color
-bool Position::isSquareInCheck(int x,int y,piece dc,variant Vr=REGULAR) {
+bool Position::isSquareInCheck(int x,int y,piece dc,variant Vr) {
   int i,j;
 
   //  cerr << "is square in check " << (char)('a'+x) << (y+1) << " ";
@@ -1208,7 +1208,7 @@
   return false;
 }
 
-bool Position::isInCheck(piece c,variant Vr=REGULAR) {
+bool Position::isInCheck(piece c,variant Vr) {
   int i,j,kx,ky;
 
   // FIXME: check rules for giveaway and losers variants
@@ -1228,7 +1228,7 @@
   return(isSquareInCheck(kx,ky,c,Vr));
 }
 
-bool Position::isMate(piece c,variant Vr=REGULAR) {
+bool Position::isMate(piece c,variant Vr) {
   int i,j,m,n;
   Position after;
 
