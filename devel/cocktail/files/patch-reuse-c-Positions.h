--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Positions.h	Tue Feb 15 14:26:38 1994
+++ ./reuse/c/Positions.h	Fri Sep 10 13:35:03 2004
@@ -27,7 +27,7 @@
 extern tPosition NoPosition;
 			/* A default position (0, 0).			*/
 
-extern int  Compare	  ARGS((tPosition Position1, tPosition Position2));
+extern int  Compare	  ARGS((const tPosition Position1, const tPosition Position2));
 			/* Returns -1 if Position1 < Position2.		*/
 			/* Returns  0 if Position1 = Position2.		*/
 			/* Returns  1 if Position1 > Position2.		*/
