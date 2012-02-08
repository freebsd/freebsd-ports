--- hack/hack.shk.c.orig	Sun May 27 21:36:53 2007
+++ hack/hack.shk.c	Sun May 27 21:38:28 2007
@@ -131,11 +131,11 @@ struct bill_x *bp = bill;
 	}
 }
 
+static void findshk();
+
 inshop(){
 int roomno = inroom(u.ux,u.uy);
 
-	static void findshk();
-
 	/* Did we just leave a shop? */
 	if(u.uinshop &&
 	    (u.uinshop != roomno + 1 || shlevel != dlevel || !shopkeeper)) {
@@ -308,14 +308,14 @@ struct monst *shkp;
 	}
 }
 
+static int dopayobj();
+
 dopay(){
 long ltmp;
 struct bill_x *bp;
 struct monst *shkp;
 int pass, tmp;
 
-	static int dopayobj();
-
 	multi = 0;
 	(void) inshop();
 	for(shkp = fmon; shkp; shkp = shkp->nmon)
@@ -692,10 +692,11 @@ quit:
 	return(0);
 }
 
+static int realhunger();
+
 static
 getprice(obj) struct obj *obj; {
 int tmp, ac;
-	static int realhunger();
 
 	switch(obj->olet){
 	case AMULET_SYM:
