--- syspred1.c.orig	Thu Dec 14 22:30:29 2006
+++ syspred1.c	Thu Dec 14 22:35:14 2006
@@ -1094,6 +1094,7 @@
   struct clause *root;
   register struct term *tt, *temp;
           int pos = 0, arity;
+  struct term *tt1;
 
 	  if (is_atomic(t)) return((struct clause *)NIL);
           if ((arity = t->t_arity)==0) return((struct clause *)NIL);
@@ -1105,8 +1106,9 @@
 	    head_of_list(tt) = Arg(t,pos);
 	    pos++;
             if (pos >= arity) break;
-	    tail_of_list(tt) = temp =
-	      (struct term *)Nlist(NIL,(struct clause *)NIL,TEMPORAL);
+	    tt1 = tail_of_list(tt);
+	    temp = (struct term *)Nlist(NIL,(struct clause *)NIL,TEMPORAL);
+	    tt1 = (struct term *)Nlist(NIL,(struct clause *)NIL,TEMPORAL);
 	    tt = temp;
 	  }
 	  return(root);
@@ -1227,8 +1229,7 @@
 	head_of_list(t) = Nstr(s, TEMPORAL);
       }
       if (nbuf[pos] == '\0') return(root);
-      t = (tail_of_list(t) =
-	   (struct term *)Nlist(NIL,(struct clause *)NIL,TEMPORAL));
+      t = (struct term *)Nlist(NIL,(struct clause *)NIL,TEMPORAL);
     }
 }
 
