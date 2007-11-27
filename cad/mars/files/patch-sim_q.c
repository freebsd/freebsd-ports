--- sim/q.c.orig	1992-10-07 04:52:52.000000000 +0100
+++ sim/q.c	2007-11-23 22:23:21.000000000 +0100
@@ -23,8 +23,6 @@
 
 extern char *sim_calloc(), *sim_malloc();
 
-#define NULL 0
-
 /* If using GCC, this function is declared inline in q.h. */
 #ifndef INLINE
 q_elt *
@@ -95,7 +93,7 @@
 	    return TRUE;
 	  }
 
-	return NULL;		/* not in queue, fail */
+	return 0;		/* not in queue, fail */
 }
 
 q_del(q, elt)
@@ -120,7 +118,7 @@
 	    return TRUE;
 	  }
 
-	return NULL;		/* not in queue, fail */
+	return 0;		/* not in queue, fail */
 }
 
   
