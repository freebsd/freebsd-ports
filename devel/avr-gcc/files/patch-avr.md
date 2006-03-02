--- gcc/config/avr/avr.md.orig	Sat Mar 19 16:45:41 2005
+++ gcc/config/avr/avr.md	Thu Mar  2 09:45:36 2006
@@ -346,69 +346,75 @@
 
 ;;=========================================================================
 ;; move string (like memcpy)
-;; implement as RTL loop
 
 (define_expand "movstrhi"
   [(parallel [(set (match_operand:BLK 0 "memory_operand" "")
-          (match_operand:BLK 1 "memory_operand" ""))
-          (use (match_operand:HI 2 "const_int_operand" ""))
-          (use (match_operand:HI 3 "const_int_operand" ""))])]
+		   (match_operand:BLK 1 "memory_operand" ""))
+	      (use (match_operand:HI 2 "const_int_operand" ""))
+	      (use (match_operand:HI 3 "const_int_operand" ""))
+	      (clobber (match_scratch:HI 4 ""))
+	      (clobber (match_scratch:HI 5 ""))
+	      (clobber (match_dup 6))])]
   ""
   "{
-  int prob;
-  HOST_WIDE_INT count;
+  rtx addr0, addr1;
+  int cnt8;
   enum machine_mode mode;
-  rtx label = gen_label_rtx ();
-  rtx loop_reg;
-  rtx jump;
-
-  /* Copy pointers into new psuedos - they will be changed.  */
-  rtx addr0 = copy_to_mode_reg (Pmode, XEXP (operands[0], 0));
-  rtx addr1 = copy_to_mode_reg (Pmode, XEXP (operands[1], 0));
-
-  /* Create rtx for tmp register - we use this as scratch.  */
-  rtx tmp_reg_rtx  = gen_rtx_REG (QImode, TMP_REGNO);
 
   if (GET_CODE (operands[2]) != CONST_INT)
     FAIL;
-
-  count = INTVAL (operands[2]);
-  if (count <= 0)
-    FAIL;
-
-  /* Work out branch probability for latter use.  */
-  prob = REG_BR_PROB_BASE - REG_BR_PROB_BASE / count;
-
-  /* See if constant fit 8 bits.  */
-  mode = (count < 0x100) ? QImode : HImode;
-  /* Create loop counter register.  */
-  loop_reg = copy_to_mode_reg (mode, gen_int_mode (count, mode));
-
-  /* Now create RTL code for move loop.  */
-  /* Label at top of loop.  */
-  emit_label (label);
-
-  /* Move one byte into scratch and inc pointer.  */
-  emit_move_insn (tmp_reg_rtx, gen_rtx_MEM (QImode, addr1));
-  emit_move_insn (addr1, gen_rtx_PLUS (Pmode, addr1, const1_rtx));
-
-  /* Move to mem and inc pointer.  */
-  emit_move_insn (gen_rtx_MEM (QImode, addr0), tmp_reg_rtx);
-  emit_move_insn (addr0, gen_rtx_PLUS (Pmode, addr0, const1_rtx));
-
-  /* Decrement count.  */
-  emit_move_insn (loop_reg, gen_rtx_PLUS (mode, loop_reg, constm1_rtx));
-
-  /* Compare with zero and jump if not equal. */
-  emit_cmp_and_jump_insns (loop_reg, const0_rtx, NE, NULL_RTX, mode, 1,
-                           label);
-  /* Set jump probability based on loop count.  */
-  jump = get_last_insn ();
-  REG_NOTES (jump) = gen_rtx_EXPR_LIST (REG_BR_PROB,
-                    GEN_INT (prob),
-                    REG_NOTES (jump));
-  DONE;
+  cnt8 = byte_immediate_operand (operands[2], GET_MODE (operands[2]));
+  mode = cnt8 ? QImode : HImode;
+  operands[2] = copy_to_mode_reg (mode,
+                                  gen_int_mode (INTVAL (operands[2]), mode));
+  addr0 = copy_to_mode_reg (Pmode, XEXP (operands[0], 0));
+  addr1 = copy_to_mode_reg (Pmode, XEXP (operands[1], 0));
+
+  operands[6] = gen_rtx_SCRATCH (mode);
+  operands[0] = gen_rtx (MEM, BLKmode, addr0);
+  operands[1] = gen_rtx (MEM, BLKmode, addr1);
 }")
+
+(define_insn "*movstrqi_insn"
+  [(set (mem:BLK (match_operand:HI 0 "register_operand" "e"))
+	(mem:BLK (match_operand:HI 1 "register_operand" "e")))
+   (use (match_operand:QI 2 "register_operand" "r"))
+   (use (match_operand:QI 3 "const_int_operand" "i"))
+   (clobber (match_scratch:HI 4 "=0"))
+   (clobber (match_scratch:HI 5 "=1"))
+   (clobber (match_scratch:QI 6 "=2"))]
+  ""
+  "ld __tmp_reg__,%a1+
+	st %a0+,__tmp_reg__
+	dec %2
+	brne .-8"
+  [(set_attr "length" "4")
+   (set_attr "cc" "clobber")])
+
+(define_insn "*movstrhi"
+  [(set (mem:BLK (match_operand:HI 0 "register_operand" "e,e"))
+	(mem:BLK (match_operand:HI 1 "register_operand" "e,e")))
+   (use (match_operand:HI 2 "register_operand" "!w,d"))
+   (use (match_operand:HI 3 "const_int_operand" ""))
+   (clobber (match_scratch:HI 4 "=0,0"))
+   (clobber (match_scratch:HI 5 "=1,1"))
+   (clobber (match_scratch:HI 6 "=2,2"))]
+  ""
+  "*{
+     if (which_alternative==0)
+       return (AS2 (ld,__tmp_reg__,%a1+) CR_TAB
+	       AS2 (st,%a0+,__tmp_reg__)  CR_TAB
+	       AS2 (sbiw,%A2,1) CR_TAB
+	       AS1 (brne,.-8));
+     else
+       return (AS2 (ld,__tmp_reg__,%a1+) CR_TAB
+	       AS2 (st,%a0+,__tmp_reg__)  CR_TAB
+	       AS2 (subi,%A2,1) CR_TAB
+	       AS2 (sbci,%B2,0) CR_TAB
+	       AS1 (brne,.-10));
+}"
+  [(set_attr "length" "4,5")
+   (set_attr "cc" "clobber,clobber")])
 
 ;; =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0 =0
 ;; memset (%0, 0, %1)
