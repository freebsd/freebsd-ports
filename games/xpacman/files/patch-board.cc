--- board.cc.orig	Tue Jul 18 11:03:22 1995
+++ board.cc	Mon Mar 10 20:52:04 2008
@@ -119,7 +119,7 @@
  oldtemp=oldlist;
  while (oldtemp) {	//delete elements in the now previous sprite list
   oldnext=oldtemp->next;
-  delete oldnext;
+  delete oldtemp;
   oldtemp=oldnext;
  }
 if (zero && oldlist) {	//personal thingie used for debug, not useful
@@ -157,6 +157,7 @@
 void Board::sprite(DynamicElement *g) {	//let dynamicelement be a sprite
  liststruct *temp=0,*last=0;		//resets to null
  liststruct *ny=new liststruct;		//get a new liststruct
+ ny->next = 0;
  ny->g=g;				//get pointer to element
  ny->gid=g->getgid();			//get it's grafical id
  g->getxy(&ny->x,&ny->y);		//and coordinates
