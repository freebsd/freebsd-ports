Index: gcc/regrename.c
===================================================================
RCS file: /cvs/gcc/gcc/gcc/regrename.c,v
retrieving revision 1.72
retrieving revision 1.73
diff -u -3 -p -r1.72 -r1.73
--- gcc/regrename.c	14 Jan 2004 16:25:09 -0000	1.72
+++ gcc/regrename.c	14 Jan 2004 17:55:20 -0000	1.73
@@ -1345,8 +1345,8 @@ find_oldest_value_reg (enum reg_class cl
 	if (!TEST_HARD_REG_BIT (reg_class_contents[class], last))
 	  return NULL_RTX;
 
-      if (new = maybe_mode_change (oldmode, vd->e[regno].mode, mode, i,
-				   regno))
+      new = maybe_mode_change (oldmode, vd->e[regno].mode, mode, i, regno);
+      if (new)
 	{
 	  ORIGINAL_REGNO (new) = ORIGINAL_REGNO (reg);
 	  REG_ATTRS (new) = REG_ATTRS (reg);
