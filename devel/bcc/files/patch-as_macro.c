--- as/macro.c.orig	1993-07-10 19:08:23 UTC
+++ as/macro.c
@@ -120,7 +120,7 @@ PUBLIC void pmacro()
 	    else
 		symptr->type |= MACBIT;
 	    symptr->data = UNDBIT;	/* undefined till end */
-	    symptr->value_reg_or_op.value = (unsigned) heapptr;
+	    symptr->value_reg_or_op.value = (offset_t) heapptr;
 					/* beginning of store for macro */
 					/* value s.b. (char *) */
 	    getsym_nolookup();		/* test for "C" */
