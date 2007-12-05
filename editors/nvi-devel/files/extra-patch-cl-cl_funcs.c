--- ../cl/cl_funcs.c.orig	2001-06-25 11:19:05.000000000 -0400
+++ ../cl/cl_funcs.c	2007-11-15 14:18:45.000000000 -0500
@@ -381,7 +381,7 @@
 
 	    if (CLSP(discardp)) {
 		    delwin(CLSP(discardp));
-		    CLSP(discardp) = NULL;
+		    LCLSP(discardp) = NULL;
 	    }
 	}
 
@@ -395,7 +395,7 @@
 
 		if (CLSP(tsp))
 			delwin(CLSP(tsp));
-		CLSP(tsp) = subwin(stdscr, tsp->rows, tsp->cols,
+		LCLSP(tsp) = subwin(stdscr, tsp->rows, tsp->cols,
 					   tsp->roff, tsp->coff);
 	}
 
@@ -716,9 +716,9 @@
 	if (CLSP(origp))
 		delwin(CLSP(origp));
 
-	CLSP(origp) = subwin(stdscr, origp->rows, origp->cols,
+	LCLSP(origp) = subwin(stdscr, origp->rows, origp->cols,
 				     origp->roff, origp->coff);
-	CLSP(newp) = subwin(stdscr, newp->rows, newp->cols,
+	LCLSP(newp) = subwin(stdscr, newp->rows, newp->cols,
 				     newp->roff, newp->coff);
 
 	/* origp is the original screen, giving up space to newp. */
