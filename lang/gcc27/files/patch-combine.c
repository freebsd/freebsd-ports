--- combine.c.orig	Sun Nov 26 11:32:07 1995
+++ combine.c	Mon Mar 20 13:29:10 2000
@@ -440,7 +440,7 @@
 static int use_crosses_set_p	PROTO((rtx, int));
 static void reg_dead_at_p_1	PROTO((rtx, rtx));
 static int reg_dead_at_p	PROTO((rtx, rtx));
-static void move_deaths		PROTO((rtx, int, rtx, rtx *));
+static void move_deaths		PROTO((rtx, rtx, int, rtx, rtx *));
 static int reg_bitfield_target_p  PROTO((rtx, rtx));
 static void distribute_notes	PROTO((rtx, rtx, rtx, rtx, rtx, rtx));
 static void distribute_links	PROTO((rtx));
@@ -2077,8 +2077,38 @@
 			undobuf.other_insn, NULL_RTX, NULL_RTX, NULL_RTX);
     }
 
-  /* We now know that we can do this combination.  Merge the insns and 
-     update the status of registers and LOG_LINKS.  */
+  /* We now know that we can do this combination.  */
+
+  /* Earlier we did all the checks required to determine if we could
+     logically combine three insns into one.  Then we determined that
+     the machine description would not let us do it in one, but would
+     let us do it in two.  Thus when generating two insns, they must,
+     in general, be adjacent -- one logical instruction if you will.
+
+     We could be complicated and figure out some rules that would allow
+     us to not move the insn, but it seems likely that the scheduler will
+     do as good with no muss.  */
+
+  if (newi2pat && NEXT_INSN (i2) != i3)
+    {
+      rtx n = NEXT_INSN(i2);
+      int c = INSN_CUID(i2);
+
+      /* Move the instruction */
+      reorder_insns(i2, i2, PREV_INSN (i3));
+
+      /* Update the CUID map */
+      while (1)
+        {
+	  uid_cuid[INSN_UID (n)] = c;
+	  if (n == i2)
+	    break;
+	  n = NEXT_INSN(n);
+	  ++c;
+	}
+    }
+
+  /* Merge the insns and update the status of registers and LOG_LINKS.  */
 
   {
     rtx i3notes, i2notes, i1notes = 0;
@@ -2186,11 +2216,18 @@
       }
 
     /* Get death notes for everything that is now used in either I3 or
-       I2 and used to die in a previous insn.  */
+       I2 and used to die in a previous insn.  If we built two new 
+       patterns, move from i1 to i2 then i2 to i3 so that we get the
+       proper movement on registers that i2 modifies.  */
 
-    move_deaths (newpat, i1 ? INSN_CUID (i1) : INSN_CUID (i2), i3, &midnotes);
     if (newi2pat)
-      move_deaths (newi2pat, INSN_CUID (i1), i2, &midnotes);
+      {
+	move_deaths (newi2pat, NULL_RTX, INSN_CUID (i1), i2, &midnotes);
+	move_deaths (newpat, newi2pat, INSN_CUID (i1), i3, &midnotes);
+      }
+    else
+      move_deaths (newpat, NULL_RTX, i1 ? INSN_CUID (i1) : INSN_CUID (i2),
+		   i3, &midnotes);
 
     /* Distribute all the LOG_LINKS and REG_NOTES from I1, I2, and I3.  */
     if (i3notes)
@@ -10372,12 +10409,15 @@
    TO_INSN (exclusive), put a REG_DEAD note for that register in the
    list headed by PNOTES. 
 
+   That said, don't move registers killed by maybe_kill_insn.
+
    This is done when X is being merged by combination into TO_INSN.  These
    notes will then be distributed as needed.  */
 
 static void
-move_deaths (x, from_cuid, to_insn, pnotes)
+move_deaths (x, maybe_kill_insn, from_cuid, to_insn, pnotes)
      rtx x;
+     rtx maybe_kill_insn;
      int from_cuid;
      rtx to_insn;
      rtx *pnotes;
@@ -10392,6 +10432,11 @@
       register rtx where_dead = reg_last_death[regno];
       register rtx before_dead, after_dead;
 
+      /* Don't move the register if it gets killed in between from and to */
+      if (maybe_kill_insn && reg_set_p (x, maybe_kill_insn)
+	  && !reg_referenced_p (x, maybe_kill_insn))
+	return;
+
       /* WHERE_DEAD could be a USE insn made by combine, so first we
 	 make sure that we have insns with valid INSN_CUID values.  */
       before_dead = where_dead;
@@ -10449,7 +10494,7 @@
 
 	      for (i = regno + 1; i < ourend; i++)
 		move_deaths (gen_rtx (REG, reg_raw_mode[i], i),
-			     from_cuid, to_insn, &oldnotes);
+			     maybe_kill_insn, from_cuid, to_insn, &oldnotes);
 	    }
 
 	  if (note != 0 && GET_MODE (XEXP (note, 0)) == GET_MODE (x))
@@ -10470,7 +10515,7 @@
     {
       rtx dest = SET_DEST (x);
 
-      move_deaths (SET_SRC (x), from_cuid, to_insn, pnotes);
+      move_deaths (SET_SRC (x), maybe_kill_insn, from_cuid, to_insn, pnotes);
 
       /* In the case of a ZERO_EXTRACT, a STRICT_LOW_PART, or a SUBREG
 	 that accesses one word of a multi-word item, some
@@ -10485,7 +10530,7 @@
 		  == ((GET_MODE_SIZE (GET_MODE (SUBREG_REG (dest)))
 		       + UNITS_PER_WORD - 1) / UNITS_PER_WORD))))
 	{
-	  move_deaths (dest, from_cuid, to_insn, pnotes);
+	  move_deaths (dest, maybe_kill_insn, from_cuid, to_insn, pnotes);
 	  return;
 	}
 
@@ -10499,7 +10544,8 @@
 	 being replaced so the old value is not used in this insn.  */
 
       if (GET_CODE (dest) == MEM)
-	move_deaths (XEXP (dest, 0), from_cuid, to_insn, pnotes);
+	move_deaths (XEXP (dest, 0), maybe_kill_insn, from_cuid,
+		     to_insn, pnotes);
       return;
     }
 
@@ -10515,10 +10561,11 @@
 	{
 	  register int j;
 	  for (j = XVECLEN (x, i) - 1; j >= 0; j--)
-	    move_deaths (XVECEXP (x, i, j), from_cuid, to_insn, pnotes);
+	    move_deaths (XVECEXP (x, i, j), maybe_kill_insn, from_cuid,
+			 to_insn, pnotes);
 	}
       else if (fmt[i] == 'e')
-	move_deaths (XEXP (x, i), from_cuid, to_insn, pnotes);
+	move_deaths (XEXP (x, i), maybe_kill_insn, from_cuid, to_insn, pnotes);
     }
 }
 
