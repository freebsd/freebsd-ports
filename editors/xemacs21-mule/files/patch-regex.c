Index: src/regex.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/regex.c,v
retrieving revision 1.25.2.10
retrieving revision 1.25.2.8
diff -u -r1.25.2.10 -r1.25.2.8
--- src/regex.c	2004/10/08 00:40:33	1.25.2.10
+++ src/regex.c	2004/03/15 03:34:59	1.25.2.8
@@ -418,7 +418,7 @@
 
         /* Start remembering the text that is matched, for storing in a
            register.  Followed by one byte with the register number, in
-           the range 1 to the pattern buffer's re_ngroups
+           the range 0 to one less than the pattern buffer's re_nsub
            field.  Then followed by one byte with the number of groups
            inner to this one.  (This last has to be part of the
            start_memory only because we need it in the on_failure_jump
@@ -427,7 +427,7 @@
 
         /* Stop remembering the text that is matched and store it in a
            memory register.  Followed by one byte with the register
-           number, in the range 1 to `re_ngroups' in the
+           number, in the range 0 to one less than `re_nsub' in the
            pattern buffer, and one byte with the number of inner groups,
            just like `start_memory'.  (We need the number of inner
            groups here because we don't have any easy way of finding the
@@ -974,7 +974,6 @@
     }
 
   printf ("re_nsub: %ld\t", (long)bufp->re_nsub);
-  printf ("re_ngroups: %ld\t", (long)bufp->re_ngroups);
   printf ("regs_alloc: %d\t", bufp->regs_allocated);
   printf ("can_be_null: %d\t", bufp->can_be_null);
   printf ("newline_anchor: %d\n", bufp->newline_anchor);
@@ -984,20 +983,6 @@
   printf ("syntax: %d\n", bufp->syntax);
   /* Perhaps we should print the translate table?  */
   /* and maybe the category table? */
-
-  if (bufp->external_to_internal_register)
-    {
-      int i;
-
-      printf ("external_to_internal_register:\n");
-      for (i = 0; i <= bufp->re_nsub; i++)
-	{
-	  if (i > 0)
-	    printf (", ");
-	  printf ("%d -> %d", i, bufp->external_to_internal_register[i]);
-	}
-      printf ("\n");
-    }
 }
 
 
@@ -1708,7 +1693,6 @@
    ignore the excess.  */
 typedef unsigned regnum_t;
 
-#define INIT_REG_TRANSLATE_SIZE 5
 
 /* Macros for the compile stack.  */
 
@@ -1892,9 +1876,7 @@
      `syntax' is set to SYNTAX;
      `used' is set to the length of the compiled pattern;
      `fastmap_accurate' is zero;
-     `re_ngroups' is the number of groups/subexpressions (including shy
-        groups) in PATTERN;
-     `re_nsub' is the number of non-shy groups in PATTERN;
+     `re_nsub' is the number of subexpressions in PATTERN;
      `not_bol' and `not_eol' are zero;
 
    The `fastmap' and `newline_anchor' fields are neither
@@ -1992,23 +1974,6 @@
 
   /* Always count groups, whether or not bufp->no_sub is set.  */
   bufp->re_nsub = 0;
-  bufp->re_ngroups = 0;
-
-  if (bufp->external_to_internal_register == 0)
-    {
-      bufp->external_to_internal_register_size = INIT_REG_TRANSLATE_SIZE;
-      RETALLOC (bufp->external_to_internal_register,
-		bufp->external_to_internal_register_size,
-		int);
-    }
-
-  {
-    int i;
-
-    bufp->external_to_internal_register[0] = 0;
-    for (i = 1; i < bufp->external_to_internal_register_size; i++)
-      bufp->external_to_internal_register[i] = (int) 0xDEADBEEF;
-  }
 
 #if !defined (emacs) && !defined (SYNTAX_TABLE)
   /* Initialize the syntax table.  */
@@ -2591,7 +2556,6 @@
             handle_open:
               {
                 regnum_t r;
-		int shy = 0;
 
                 if (!(syntax & RE_NO_SHY_GROUPS)
                     && p != pend
@@ -2602,7 +2566,7 @@
                     switch (c)
                       {
                       case ':': /* shy groups */
-                        shy = 1;
+                        r = MAX_REGNUM + 1;
                         break;
 
                       /* All others are reserved for future constructs. */
@@ -2610,32 +2574,11 @@
                         FREE_STACK_RETURN (REG_BADPAT);
                       }
                   }
-
-		r = ++regnum;
-		bufp->re_ngroups++;
-		if (!shy)
-		  {
-		    bufp->re_nsub++;
-		    while (bufp->external_to_internal_register_size <=
-			   bufp->re_nsub)
-		      {
-			int i;
-			int old_size =
-			  bufp->external_to_internal_register_size;
-			bufp->external_to_internal_register_size += 5;
-			RETALLOC (bufp->external_to_internal_register,
-				  bufp->external_to_internal_register_size,
-				  int);
-			/* debugging */
-			for (i = old_size;
-			     i < bufp->external_to_internal_register_size; i++)
-			  bufp->external_to_internal_register[i] =
-			    (int) 0xDEADBEEF;
-		      }
-
-		    bufp->external_to_internal_register[bufp->re_nsub] =
-		      bufp->re_ngroups;
-		  }
+                else
+                  {
+                    bufp->re_nsub++;
+                    r = ++regnum;
+                  }
 
                 if (COMPILE_STACK_FULL)
                   {
@@ -2659,10 +2602,7 @@
                 /* We will eventually replace the 0 with the number of
                    groups inner to this one.  But do not push a
                    start_memory for groups beyond the last one we can
-                   represent in the compiled pattern.
-		   #### bad bad bad.  this will fail in lots of ways, if we
-		   ever have to backtrack for these groups.
-		*/
+                   represent in the compiled pattern.  */
                 if (r <= MAX_REGNUM)
                   {
                     COMPILE_STACK_TOP.inner_group_offset
@@ -3052,23 +2992,18 @@
             case '1': case '2': case '3': case '4': case '5':
             case '6': case '7': case '8': case '9':
 	      {
-		int reg;
+		regnum_t reg;
 		if (syntax & RE_NO_BK_REFS)
 		  goto normal_char;
 
 		reg = c - '0';
 
-		if (reg > bufp->re_nsub)
+		if (reg > regnum)
 		  FREE_STACK_RETURN (REG_ESUBREG);
 
-		{
-		  int regint = bufp->external_to_internal_register[reg];
-		  /* Can't back reference to a subexpression if inside it. */
-		  if (group_in_compile_stack (compile_stack, regint))
-		    {
-		      goto normal_char;
-		    }
-		}
+		/* Can't back reference to a subexpression if inside of it.  */
+		if (group_in_compile_stack (compile_stack, reg))
+		  goto normal_char;
 
 		laststart = buf_end;
 		BUF_PUSH_2 (duplicate, reg);
@@ -3186,7 +3121,7 @@
      isn't necessary unless we're trying to avoid calling alloca in
      the search and match routines.  */
   {
-    int num_regs = bufp->re_ngroups + 1;
+    int num_regs = bufp->re_nsub + 1;
 
     /* Since DOUBLE_FAIL_STACK refuses to double only if the current size
        is strictly greater than re_max_failures, the largest possible stack
@@ -4449,7 +4384,7 @@
   /* We fill all the registers internally, independent of what we
      return, for use in backreferences.  The number here includes
      an element for register zero.  */
-  int num_regs = bufp->re_ngroups + 1;
+  int num_regs = bufp->re_nsub + 1;
 
   /* The currently active registers.  */
   int lowest_active_reg = NO_LOWEST_ACTIVE_REG;
@@ -4535,7 +4470,7 @@
      there are groups, we include space for register 0 (the whole
      pattern), even though we never use it, since it simplifies the
      array indexing.  We should fix this.  */
-  if (bufp->re_ngroups)
+  if (bufp->re_nsub)
     {
       regstart       = REGEX_TALLOC (num_regs, re_char *);
       regend         = REGEX_TALLOC (num_regs, re_char *);
@@ -4711,87 +4646,80 @@
           DEBUG_PRINT1 ("Accepting match.\n");
 
           /* If caller wants register contents data back, do it.  */
-	  {
-	    int num_nonshy_regs = bufp->re_nsub + 1;
-	    if (regs && !bufp->no_sub)
-	      {
-		/* Have the register data arrays been allocated?  */
-		if (bufp->regs_allocated == REGS_UNALLOCATED)
-		  { /* No.  So allocate them with malloc.  We need one
-		       extra element beyond `num_regs' for the `-1' marker
-		       GNU code uses.  */
-		    regs->num_regs = MAX (RE_NREGS, num_nonshy_regs + 1);
-		    regs->start = TALLOC (regs->num_regs, regoff_t);
-		    regs->end = TALLOC (regs->num_regs, regoff_t);
-		    if (regs->start == NULL || regs->end == NULL)
-		      {
-			FREE_VARIABLES ();
-			return -2;
-		      }
-		    bufp->regs_allocated = REGS_REALLOCATE;
-		  }
-		else if (bufp->regs_allocated == REGS_REALLOCATE)
-		  { /* Yes.  If we need more elements than were already
-		       allocated, reallocate them.  If we need fewer, just
-		       leave it alone.  */
-		    if (regs->num_regs < num_nonshy_regs + 1)
-		      {
-			regs->num_regs = num_nonshy_regs + 1;
-			RETALLOC (regs->start, regs->num_regs, regoff_t);
-			RETALLOC (regs->end, regs->num_regs, regoff_t);
-			if (regs->start == NULL || regs->end == NULL)
-			  {
-			    FREE_VARIABLES ();
-			    return -2;
-			  }
-		      }
-		  }
-		else
-		  {
-		    /* The braces fend off a "empty body in an else-statement"
-		       warning under GCC when assert expands to nothing.  */
-		    assert (bufp->regs_allocated == REGS_FIXED);
-		  }
-
-		/* Convert the pointer data in `regstart' and `regend' to
-		   indices.  Register zero has to be set differently,
-		   since we haven't kept track of any info for it.  */
-		if (regs->num_regs > 0)
-		  {
-		    regs->start[0] = pos;
-		    regs->end[0] = (MATCHING_IN_FIRST_STRING
-				    ? ((regoff_t) (d - string1))
-				    : ((regoff_t) (d - string2 + size1)));
-		  }
+          if (regs && !bufp->no_sub)
+	    {
+              /* Have the register data arrays been allocated?  */
+              if (bufp->regs_allocated == REGS_UNALLOCATED)
+                { /* No.  So allocate them with malloc.  We need one
+                     extra element beyond `num_regs' for the `-1' marker
+                     GNU code uses.  */
+                  regs->num_regs = MAX (RE_NREGS, num_regs + 1);
+                  regs->start = TALLOC (regs->num_regs, regoff_t);
+                  regs->end = TALLOC (regs->num_regs, regoff_t);
+                  if (regs->start == NULL || regs->end == NULL)
+		    {
+		      FREE_VARIABLES ();
+		      return -2;
+		    }
+                  bufp->regs_allocated = REGS_REALLOCATE;
+                }
+              else if (bufp->regs_allocated == REGS_REALLOCATE)
+                { /* Yes.  If we need more elements than were already
+                     allocated, reallocate them.  If we need fewer, just
+                     leave it alone.  */
+                  if (regs->num_regs < num_regs + 1)
+                    {
+                      regs->num_regs = num_regs + 1;
+                      RETALLOC (regs->start, regs->num_regs, regoff_t);
+                      RETALLOC (regs->end, regs->num_regs, regoff_t);
+                      if (regs->start == NULL || regs->end == NULL)
+			{
+			  FREE_VARIABLES ();
+			  return -2;
+			}
+                    }
+                }
+              else
+		{
+		  /* These braces fend off a "empty body in an else-statement"
+		     warning under GCC when assert expands to nothing.  */
+		  assert (bufp->regs_allocated == REGS_FIXED);
+		}
 
-		/* Go through the first `min (num_regs, regs->num_regs)'
-		   registers, since that is all we initialized.  */
-		for (mcnt = 1;
-		     mcnt < MIN (num_nonshy_regs, regs->num_regs);
-		     mcnt++)
-		  {
-		    int ireg = bufp->external_to_internal_register[mcnt];
+              /* Convert the pointer data in `regstart' and `regend' to
+                 indices.  Register zero has to be set differently,
+                 since we haven't kept track of any info for it.  */
+              if (regs->num_regs > 0)
+                {
+                  regs->start[0] = pos;
+                  regs->end[0] = (MATCHING_IN_FIRST_STRING
+				  ? ((regoff_t) (d - string1))
+			          : ((regoff_t) (d - string2 + size1)));
+                }
 
-		    if (REG_UNSET (regstart[ireg]) || REG_UNSET (regend[ireg]))
-		      regs->start[mcnt] = regs->end[mcnt] = -1;
-		    else
-		      {
-			regs->start[mcnt]
-			  = (regoff_t) POINTER_TO_OFFSET (regstart[ireg]);
-			regs->end[mcnt]
-			  = (regoff_t) POINTER_TO_OFFSET (regend[ireg]);
-		      }
-		  }
-	      } /* regs && !bufp->no_sub */
-	  }
+              /* Go through the first `min (num_regs, regs->num_regs)'
+                 registers, since that is all we initialized.  */
+	      for (mcnt = 1; mcnt < MIN (num_regs, regs->num_regs); mcnt++)
+		{
+                  if (REG_UNSET (regstart[mcnt]) || REG_UNSET (regend[mcnt]))
+                    regs->start[mcnt] = regs->end[mcnt] = -1;
+                  else
+                    {
+		      regs->start[mcnt]
+			= (regoff_t) POINTER_TO_OFFSET (regstart[mcnt]);
+                      regs->end[mcnt]
+			= (regoff_t) POINTER_TO_OFFSET (regend[mcnt]);
+                    }
+		}
+	    } /* regs && !bufp->no_sub */
 
 	  /* If we have regs and the regs structure has more elements than
-	     were in the pattern, set the extra elements to -1.  If we
+             were in the pattern, set the extra elements to -1.  If we
 	     (re)allocated the registers, this is the case, because we
 	     always allocate enough to have at least one -1 at the end.
 
 	     We do this even when no_sub is set because some applications
-	     (XEmacs) reuse register structures which may contain stale
+             (XEmacs) reuse register structures which may contain stale
 	     information, and permit attempts to access those registers.
 
 	     It would be possible to require the caller to do this, but we'd
@@ -4801,20 +4729,20 @@
 	    for (mcnt = num_regs; mcnt < regs->num_regs; mcnt++)
 	      regs->start[mcnt] = regs->end[mcnt] = -1;
 
-	  DEBUG_PRINT4 ("%u failure points pushed, %u popped (%u remain).\n",
-			nfailure_points_pushed, nfailure_points_popped,
-			nfailure_points_pushed - nfailure_points_popped);
-	  DEBUG_PRINT2 ("%u registers pushed.\n", num_regs_pushed);
+          DEBUG_PRINT4 ("%u failure points pushed, %u popped (%u remain).\n",
+                        nfailure_points_pushed, nfailure_points_popped,
+                        nfailure_points_pushed - nfailure_points_popped);
+          DEBUG_PRINT2 ("%u registers pushed.\n", num_regs_pushed);
 
-	  mcnt = d - pos - (MATCHING_IN_FIRST_STRING
+          mcnt = d - pos - (MATCHING_IN_FIRST_STRING
 			    ? string1
 			    : string2 - size1);
 
-	  DEBUG_PRINT2 ("Returning %d from re_match_2.\n", mcnt);
+          DEBUG_PRINT2 ("Returning %d from re_match_2.\n", mcnt);
 
-	  FREE_VARIABLES ();
-	  return mcnt;
-	}
+          FREE_VARIABLES ();
+          return mcnt;
+        }
 
       /* Otherwise match next pattern command.  */
       switch (SWITCH_ENUM_CAST ((re_opcode_t) *p++))
@@ -5143,15 +5071,11 @@
 
 
 	/* \<digit> has been turned into a `duplicate' command which is
-           followed by the numeric value of <digit> as the register number.
-	   (Already passed through external-to-internal-register mapping,
-	   so it refers to the actual group number, not the non-shy-only
-	   numbering used in the external world.) */
+           followed by the numeric value of <digit> as the register number.  */
         case duplicate:
 	  {
 	    REGISTER re_char *d2, *dend2;
-	    /* Get which register to match against.  */
-	    int regno = *p++;
+	    int regno = *p++;   /* Get which register to match against.  */
 	    DEBUG_PRINT2 ("EXECUTING duplicate %d.\n", regno);
 
 	    /* Can't back reference a group which we've never matched.  */
@@ -6329,8 +6253,6 @@
      `newline_anchor' to REG_NEWLINE being set in CFLAGS;
      `fastmap' and `fastmap_accurate' to zero;
      `re_nsub' to the number of subexpressions in PATTERN.
-     (non-shy of course.  POSIX probably doesn't know about
-     shy ones, and in any case they should be invisible.)
 
    PATTERN is the address of the pattern string.
 
@@ -6373,7 +6295,7 @@
 
   if (cflags & REG_ICASE)
     {
-      int i;
+      unsigned i;
 
       preg->translate = (char *) malloc (CHAR_SET_SIZE);
       if (preg->translate == NULL)
