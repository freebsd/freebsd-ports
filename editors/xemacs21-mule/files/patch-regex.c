Index: regex.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/regex.c,v
retrieving revision 1.25.2.10
retrieving revision 1.25.2.9
diff -u -r1.25.2.10 -r1.25.2.9
--- src/regex.c	2004/10/08 00:40:33	1.25.2.10
+++ src/regex.c	2004/09/23 03:03:43	1.25.2.9
@@ -4766,20 +4766,16 @@
 
 		/* Go through the first `min (num_regs, regs->num_regs)'
 		   registers, since that is all we initialized.  */
-		for (mcnt = 1;
-		     mcnt < MIN (num_nonshy_regs, regs->num_regs);
-		     mcnt++)
+		for (mcnt = 1; mcnt < MIN (num_regs, regs->num_regs); mcnt++)
 		  {
-		    int ireg = bufp->external_to_internal_register[mcnt];
-
-		    if (REG_UNSET (regstart[ireg]) || REG_UNSET (regend[ireg]))
+		    if (REG_UNSET (regstart[mcnt]) || REG_UNSET (regend[mcnt]))
 		      regs->start[mcnt] = regs->end[mcnt] = -1;
 		    else
 		      {
 			regs->start[mcnt]
-			  = (regoff_t) POINTER_TO_OFFSET (regstart[ireg]);
+			  = (regoff_t) POINTER_TO_OFFSET (regstart[mcnt]);
 			regs->end[mcnt]
-			  = (regoff_t) POINTER_TO_OFFSET (regend[ireg]);
+			  = (regoff_t) POINTER_TO_OFFSET (regend[mcnt]);
 		      }
 		  }
 	      } /* regs && !bufp->no_sub */
