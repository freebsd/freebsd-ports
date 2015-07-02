--- display.c.orig	2015-03-16 14:39:00 UTC
+++ display.c
@@ -170,14 +170,6 @@ vtresize(int force, int newrow, int newc
 		(a) = tmp;					\
 	} while (0)
 
-#define TRYREALLOCARRAY(a, n, m) do {				\
-		void *tmp;					\
-		if ((tmp = reallocarray((a), (n), (m))) == NULL) {\
-			panic("out of memory in display code");	\
-		}						\
-		(a) = tmp;					\
-	} while (0)
-
 	/* No update needed */
 	if (!first_run && !force && !rowchanged && !colchanged)
 		return (TRUE);
@@ -206,10 +198,10 @@ vtresize(int force, int newrow, int newc
 			}
 		}
 
-		TRYREALLOCARRAY(score, newrow, newrow * sizeof(struct score));
-		TRYREALLOCARRAY(vscreen, (newrow - 1), sizeof(struct video *));
-		TRYREALLOCARRAY(pscreen, (newrow - 1), sizeof(struct video *));
-		TRYREALLOCARRAY(video, (newrow - 1), 2 * sizeof(struct video));
+		TRYREALLOC(score, newrow * newrow * sizeof(struct score));
+		TRYREALLOC(vscreen, (newrow - 1) * sizeof(struct video *));
+		TRYREALLOC(pscreen, (newrow - 1) * sizeof(struct video *));
+		TRYREALLOC(video, ((newrow - 1) * 2) * sizeof(struct video));
 
 		/*
 		 * Zero-out the entries we just allocated.
@@ -247,7 +239,6 @@ vtresize(int force, int newrow, int newc
 }
 
 #undef TRYREALLOC
-#undef TRYREALLOCARRAY
 
 /*
  * Initialize the data structures used
