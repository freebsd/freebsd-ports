--- gcc/config/mips/mips.md.orig	2005-07-29 18:25:27.000000000 +0100
+++ gcc/config/mips/mips.md	2006-05-07 14:59:33.000000000 +0100
@@ -142,6 +142,21 @@
    (UNSPEC_MTHLIP		365)
    (UNSPEC_WRDSP		366)
    (UNSPEC_RDDSP		367)
+
+   ;; Sony ALLEGREX instructions
+   (UNSPEC_WSBH 		401)
+   (UNSPEC_WSBW 		402)
+
+   (UNSPEC_CLO			403)
+   (UNSPEC_CTO			404)
+
+   (UNSPEC_CACHE		405)
+   (UNSPEC_SYNC 		406)
+
+   (UNSPEC_CEIL_W_S		407)
+   (UNSPEC_FLOOR_W_S		408)
+   (UNSPEC_ROUND_W_S		409)
+
   ]
 )
 
@@ -1601,9 +1616,9 @@
 	   (mult:DI
 	      (any_extend:DI (match_operand:SI 1 "register_operand" "d"))
 	      (any_extend:DI (match_operand:SI 2 "register_operand" "d")))))]
-  "!TARGET_64BIT && ISA_HAS_MSAC"
+  "!TARGET_64BIT && (ISA_HAS_MSAC || TARGET_ALLEGREX)"
 {
-  if (TARGET_MIPS5500)
+  if (TARGET_MIPS5500 || TARGET_ALLEGREX)
     return "msub<u>\t%1,%2";
   else
     return "msac<u>\t$0,%1,%2";
@@ -1718,12 +1733,12 @@
 	 (mult:DI (any_extend:DI (match_operand:SI 1 "register_operand" "d"))
 		  (any_extend:DI (match_operand:SI 2 "register_operand" "d")))
 	 (match_operand:DI 3 "register_operand" "0")))]
-  "(TARGET_MAD || ISA_HAS_MACC)
+  "(TARGET_MAD || ISA_HAS_MACC || TARGET_ALLEGREX)
    && !TARGET_64BIT"
 {
   if (TARGET_MAD)
     return "mad<u>\t%1,%2";
-  else if (TARGET_MIPS5500)
+  else if (TARGET_MIPS5500 || TARGET_ALLEGREX)
     return "madd<u>\t%1,%2";
   else
     /* See comment in *macc.  */
@@ -1995,6 +2010,32 @@
 ;;
 ;;  ....................
 ;;
+;;	FIND FIRST BIT INSTRUCTION
+;;
+;;  ....................
+;;
+
+(define_expand "ffs<mode>2"
+  [(set (match_operand:GPR 0 "register_operand" "")
+	(ffs:GPR (match_operand:GPR 1 "register_operand" "")))]
+  "ISA_HAS_CLZ_CLO"
+{
+  rtx r1, r2, r3, r4;
+
+  r1 = gen_reg_rtx (<MODE>mode);
+  r2 = gen_reg_rtx (<MODE>mode);
+  r3 = gen_reg_rtx (<MODE>mode);
+  r4 = gen_reg_rtx (<MODE>mode);
+  emit_insn (gen_neg<mode>2 (r1, operands[1]));
+  emit_insn (gen_and<mode>3 (r2, operands[1], r1));
+  emit_insn (gen_clz<mode>2 (r3, r2));
+  emit_move_insn (r4, GEN_INT (GET_MODE_BITSIZE (<MODE>mode)));
+  emit_insn (gen_sub<mode>3 (operands[0], r4, r3));
+  DONE;
+})
+;;
+;;  ....................
+;;
 ;;	NEGATION and ONE'S COMPLEMENT
 ;;
 ;;  ....................
@@ -4193,6 +4234,25 @@
   [(set_attr "type" "shift")
    (set_attr "mode" "<MODE>")])
 
+(define_expand "rotl<mode>3"
+  [(set (match_operand:GPR 0 "register_operand")
+      	(rotate:GPR (match_operand:GPR 1 "register_operand")
+		    (match_operand:SI 2 "arith_operand")))]
+  "ISA_HAS_ROTR_<MODE>"
+{
+  rtx temp;
+
+  if (GET_CODE (operands[2]) == CONST_INT)
+    temp = GEN_INT (GET_MODE_BITSIZE (<MODE>mode) - INTVAL (operands[2]));
+  else
+    {
+      temp = gen_reg_rtx (<MODE>mode);
+      emit_insn (gen_neg<mode>2 (temp, operands[2]));
+    }
+  emit_insn (gen_rotr<mode>3 (operands[0], operands[1], temp));
+  DONE;
+})
+
 ;;
 ;;  ....................
 ;;
@@ -5306,7 +5366,7 @@
 		 (const_int 0)])
 	 (match_operand:GPR 2 "reg_or_0_operand" "dJ,0")
 	 (match_operand:GPR 3 "reg_or_0_operand" "0,dJ")))]
-  "ISA_HAS_CONDMOVE"
+  "ISA_HAS_CONDMOVE || ISA_HAS_INT_CONDMOVE"
   "@
     mov%T4\t%0,%z2,%1
     mov%t4\t%0,%z3,%1"
@@ -5336,8 +5396,12 @@
 	(if_then_else:GPR (match_dup 5)
 			  (match_operand:GPR 2 "reg_or_0_operand")
 			  (match_operand:GPR 3 "reg_or_0_operand")))]
-  "ISA_HAS_CONDMOVE"
+  "ISA_HAS_CONDMOVE || ISA_HAS_INT_CONDMOVE"
 {
+  if (ISA_HAS_INT_CONDMOVE
+      && GET_MODE_CLASS (GET_MODE (cmp_operands[0])) == MODE_FLOAT)
+    FAIL;
+
   gen_conditional_move (operands);
   DONE;
 })
@@ -5428,3 +5492,6 @@
 ; The MIPS DSP Instructions.
 
 (include "mips-dsp.md")
+
+; Sony ALLEGREX instructions.
+(include "allegrex.md")
