$FreeBSD$

http://gcc.gnu.org/ml/gcc-patches/2003-05/msg00629.html
	Date: Wed, 7 May 2003 17:52:21 -0700
	From: Richard Henderson <rth@redhat.com>
	Subject: fix amd64 xfmode splits
	Message-ID: <20030508005221.GX27351@redhat.com>

	Test case for this is FreeBSD vfprintf.c (i.e. a tad big) and
	I wasn't able to reduce the test.  The cause is evident though:
	the second part of a 12-byte quantity is SImode, not DImode,
	and so is invalid as a base address.

	r~

* config/i386/i386.c (ix86_split_long_move): Fix base register
  mode for XFmode splits for TARGET_64BIT.

--- gcc/config/i386/i386.c.orig	Wed Mar 12 01:04:01 2003
+++ gcc/config/i386/i386.c	Sun Dec 19 10:39:53 2004
@@ -8828,15 +8828,24 @@
 	 Do an lea to the last part and use only one colliding move.  */
       else if (collisions > 1)
 	{
+	  rtx base;
+
 	  collisions = 1;
-	  emit_insn (gen_rtx_SET (VOIDmode, part[0][nparts - 1],
-				  XEXP (part[1][0], 0)));
-	  part[1][0] = change_address (part[1][0],
-				       TARGET_64BIT ? DImode : SImode,
-				       part[0][nparts - 1]);
-	  part[1][1] = adjust_address (part[1][0], VOIDmode, UNITS_PER_WORD);
+
+	  base = part[0][nparts - 1];
+
+	  /* Handle the case when the last part isn't valid for lea.
+	     Happens in 64-bit mode storing the 12-byte XFmode.  */
+	  if (GET_MODE (base) != Pmode)
+	    base = gen_rtx_REG (Pmode, REGNO (base));
+
+	  emit_insn (gen_rtx_SET (VOIDmode, base, XEXP (part[1][0], 0)));
+	  part[1][0] = replace_equiv_address (part[1][0], base);
+	  part[1][1] = replace_equiv_address (part[1][1],
+				      plus_constant (base, UNITS_PER_WORD));
 	  if (nparts == 3)
-	    part[1][2] = adjust_address (part[1][0], VOIDmode, 8);
+	    part[1][2] = replace_equiv_address (part[1][2],
+				      plus_constant (base, 8));
 	}
     }
 
