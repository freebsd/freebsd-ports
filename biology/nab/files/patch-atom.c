--- tleap/atom.c.orig	Sat Apr 20 22:35:09 2002
+++ tleap/atom.c	Sat Mar  6 08:02:25 2004
@@ -908,6 +908,7 @@
     for ( i=0; i<iBonds; i++ ) {
 	aBond = aaBond[i];
 	VP1(( "Breaking bond: %s - %s\n",
+	        sAtom1,
 		sContainerFullDescriptor( (CONTAINER)aBond, sAtom2 ) ));
 	AtomRemoveBond( aAtom, aBond );
     }
