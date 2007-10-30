--- asm/emit.c.orig	2007-10-30 11:43:34.000000000 +0100
+++ asm/emit.c	2007-10-30 11:44:37.000000000 +0100
@@ -191,7 +191,7 @@
 
 /* Try to do zero page */
 
-	if (zmode >= 0 && CheckOp(ins, zmode) >= 0)
+	if (zmode >= 0 && CheckOp(ins, zmode) >= 0) {
 		if (ivalue->type == iSegRel
 				&& ivalue->u.segrel.segment == AbsSegment
 				&& (ivalue->u.segrel.offset & ~0xFF) == 0)
@@ -207,7 +207,7 @@
 			EmitIvalue(ivalue, FALSE, 0x01);
 			return;
 		}
-
+	}
 /* Can we ONLY do zero page (but didn't)? */
 
 	if (mode < 0)
@@ -239,7 +239,7 @@
 
 /* Compute displacement to target address */
 
-	if (gPass == 2)
+	if (gPass == 2) {
 		if (ivalue->type != iSegRel || ivalue->u.segrel.segment != gSegment)
 			uerror("illegal branch address");
 		else
@@ -248,7 +248,7 @@
 			if (disp < -128 || disp > 127)
 				uerror("branch of %d bytes is out of range", disp);
 		}
-
+	    }
 /* Done */
 
 	Emit(disp);
