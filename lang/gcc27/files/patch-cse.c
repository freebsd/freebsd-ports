--- cse.c.orig	Fri Aug  8 08:30:25 1997
+++ cse.c	Mon Mar 20 13:29:11 2000
@@ -7567,10 +7567,15 @@
 	     and that's just as good as a structure element
 	     in implying that we need not invalidate scalar variables.
 	     However, we must allow QImode aliasing of scalars, because the
-	     ANSI C standard allows character pointers to alias anything.  */
+	     ANSI C standard allows character pointers to alias anything.
+	     We must also allow AND addresses, because they may generate
+	     accesses outside the object being referenced.  This is used to
+	     generate aligned addresses from unaligned adresses, e.g., the
+	     Alpha storeqi_unaligned pattern.  */
 	  if (! ((MEM_IN_STRUCT_P (written)
 		  || GET_CODE (XEXP (written, 0)) == PLUS)
-		 && GET_MODE (written) != QImode))
+		 && GET_MODE (written) != QImode
+		 && GET_CODE (XEXP (written, 0)) != AND))
 	    writes_ptr->all = 1;
 	  writes_ptr->nonscalar = 1;
 	}
