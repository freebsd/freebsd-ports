Index: src/regex.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/regex.c,v
retrieving revision 1.25.2.10
retrieving revision 1.25.2.12
diff -u -r1.25.2.10 -r1.25.2.12
--- src/regex.c	2004/10/08 00:40:33	1.25.2.10
+++ src/regex.c	2005/01/29 01:33:11	1.25.2.12
@@ -1994,6 +1994,7 @@
   bufp->re_nsub = 0;
   bufp->re_ngroups = 0;
 
+  /* Allocate index translation array if needed. */
   if (bufp->external_to_internal_register == 0)
     {
       bufp->external_to_internal_register_size = INIT_REG_TRANSLATE_SIZE;
@@ -2002,6 +2003,7 @@
 		int);
     }
 
+  /* Initialize translations to impossible value to aid debugging. */
   {
     int i;
 
@@ -2614,6 +2616,8 @@
 		r = ++regnum;
 		bufp->re_ngroups++;
 		if (!shy)
+		  /* Record the translation from capturing group index to
+		     register number, reallocating table as needed. */
 		  {
 		    bufp->re_nsub++;
 		    while (bufp->external_to_internal_register_size <=
@@ -3053,23 +3057,23 @@
             case '6': case '7': case '8': case '9':
 	      {
 		int reg;
+
 		if (syntax & RE_NO_BK_REFS)
 		  goto normal_char;
 
+		/* External register indexing. */
 		reg = c - '0';
 
 		if (reg > bufp->re_nsub)
 		  FREE_STACK_RETURN (REG_ESUBREG);
 
-		{
-		  int regint = bufp->external_to_internal_register[reg];
-		  /* Can't back reference to a subexpression if inside it. */
-		  if (group_in_compile_stack (compile_stack, regint))
-		    {
-		      goto normal_char;
-		    }
-		}
+		/* Convert external to internal as soon as possible. */
+		reg = bufp->external_to_internal_register[reg];
 
+		/* Can't back reference to a subexpression if inside it. */
+		if (group_in_compile_stack (compile_stack, reg))
+		  goto normal_char;
+
 		laststart = buf_end;
 		BUF_PUSH_2 (duplicate, reg);
 	      }
@@ -4710,8 +4714,8 @@
 	succeed_label:
           DEBUG_PRINT1 ("Accepting match.\n");
 
-          /* If caller wants register contents data back, do it.  */
 	  {
+	    /* If caller wants register contents data back, fill REGS.  */
 	    int num_nonshy_regs = bufp->re_nsub + 1;
 	    if (regs && !bufp->no_sub)
 	      {
@@ -4764,8 +4768,9 @@
 				    : ((regoff_t) (d - string2 + size1)));
 		  }
 
-		/* Go through the first `min (num_regs, regs->num_regs)'
-		   registers, since that is all we initialized.  */
+		/* Map over the NUM_NONSHY_REGS non-shy internal registers.
+		   Copy each into the corresponding external register.
+		   N.B. MCNT indexes external registers. */
 		for (mcnt = 1;
 		     mcnt < MIN (num_nonshy_regs, regs->num_regs);
 		     mcnt++)
@@ -4783,23 +4788,23 @@
 		      }
 		  }
 	      } /* regs && !bufp->no_sub */
-	  }
 
-	  /* If we have regs and the regs structure has more elements than
-	     were in the pattern, set the extra elements to -1.  If we
-	     (re)allocated the registers, this is the case, because we
-	     always allocate enough to have at least one -1 at the end.
-
-	     We do this even when no_sub is set because some applications
-	     (XEmacs) reuse register structures which may contain stale
-	     information, and permit attempts to access those registers.
-
-	     It would be possible to require the caller to do this, but we'd
-	     have to change the API for this function to reflect that, and
-	     audit all callers. */
-	  if (regs && regs->num_regs > 0)
-	    for (mcnt = num_regs; mcnt < regs->num_regs; mcnt++)
-	      regs->start[mcnt] = regs->end[mcnt] = -1;
+	    /* If we have regs and the regs structure has more elements than
+	       were in the pattern, set the extra elements to -1.  If we
+	       (re)allocated the registers, this is the case, because we
+	       always allocate enough to have at least one -1 at the end.
+
+	       We do this even when no_sub is set because some applications
+	       (XEmacs) reuse register structures which may contain stale
+	       information, and permit attempts to access those registers.
+
+	       It would be possible to require the caller to do this, but we'd
+	       have to change the API for this function to reflect that, and
+	       audit all callers. */
+	    if (regs && regs->num_regs > 0)
+	      for (mcnt = num_nonshy_regs; mcnt < regs->num_regs; mcnt++)
+		regs->start[mcnt] = regs->end[mcnt] = -1;
+	  }
 
 	  DEBUG_PRINT4 ("%u failure points pushed, %u popped (%u remain).\n",
 			nfailure_points_pushed, nfailure_points_popped,
@@ -5958,7 +5963,7 @@
 
 static re_bool
 group_match_null_string_p (unsigned char **p, unsigned char *end,
-			   register_info_type *reg_info)
+			   register_info_type *register_info)
 {
   int mcnt;
   /* Point to after the args to the start_memory.  */
@@ -6007,7 +6012,7 @@
                      its number.  */
 
                   if (!alt_match_null_string_p (p1, p1 + mcnt - 3,
-				                      reg_info))
+				                      register_info))
                     return false;
 
                   /* Move to right after this alternative, including the
@@ -6036,7 +6041,7 @@
                  the length of the alternative.  */
               EXTRACT_NUMBER (mcnt, p1 - 2);
 
-              if (!alt_match_null_string_p (p1, p1 + mcnt, reg_info))
+              if (!alt_match_null_string_p (p1, p1 + mcnt, register_info))
                 return false;
 
               p1 += mcnt;	/* Get past the n-th alternative.  */
@@ -6051,7 +6056,7 @@
 
 
         default:
-          if (!common_op_match_null_string_p (&p1, end, reg_info))
+          if (!common_op_match_null_string_p (&p1, end, register_info))
             return false;
         }
     } /* while p1 < end */
@@ -6066,7 +6071,7 @@
 
 static re_bool
 alt_match_null_string_p (unsigned char *p, unsigned char *end,
-			 register_info_type *reg_info)
+			 register_info_type *register_info)
 {
   int mcnt;
   unsigned char *p1 = p;
@@ -6086,7 +6091,7 @@
           break;
 
 	default:
-          if (!common_op_match_null_string_p (&p1, end, reg_info))
+          if (!common_op_match_null_string_p (&p1, end, register_info))
             return false;
         }
     }  /* while p1 < end */
@@ -6102,7 +6107,7 @@
 
 static re_bool
 common_op_match_null_string_p (unsigned char **p, unsigned char *end,
-			       register_info_type *reg_info)
+			       register_info_type *register_info)
 {
   int mcnt;
   re_bool ret;
@@ -6130,13 +6135,14 @@
     case start_memory:
       reg_no = *p1;
       assert (reg_no > 0 && reg_no <= MAX_REGNUM);
-      ret = group_match_null_string_p (&p1, end, reg_info);
+      ret = group_match_null_string_p (&p1, end, register_info);
 
       /* Have to set this here in case we're checking a group which
          contains a group and a back reference to it.  */
 
-      if (REG_MATCH_NULL_STRING_P (reg_info[reg_no]) == MATCH_NULL_UNSET_VALUE)
-        REG_MATCH_NULL_STRING_P (reg_info[reg_no]) = ret;
+      if (REG_MATCH_NULL_STRING_P (register_info[reg_no]) ==
+	  MATCH_NULL_UNSET_VALUE)
+        REG_MATCH_NULL_STRING_P (register_info[reg_no]) = ret;
 
       if (!ret)
         return false;
@@ -6167,7 +6173,7 @@
       break;
 
     case duplicate:
-      if (!REG_MATCH_NULL_STRING_P (reg_info[*p1]))
+      if (!REG_MATCH_NULL_STRING_P (register_info[*p1]))
         return false;
       break;
 
