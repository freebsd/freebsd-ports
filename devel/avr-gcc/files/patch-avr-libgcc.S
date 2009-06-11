Note: this patch is misnamed.  It actually adds support for
ATmega256x.  I'll stick with the name since CVS is poor at
renaming files. -- Joerg

Index: gcc/config/avr/libgcc.S
===================================================================
--- gcc/config/avr/libgcc.S	(revision 132252)
+++ gcc/config/avr/libgcc.S	(working copy)
@@ -594,7 +594,12 @@
 	out	__SP_H__,r29
 	out	__SREG__,__tmp_reg__
 	out	__SP_L__,r28
+#if defined (__AVR_HAVE_EIJMP_EICALL__)
+	eijmp
+#else
 	ijmp
+#endif
+
 .endfunc
 #endif /* defined (L_prologue) */
 
@@ -674,13 +679,22 @@
 	lpm	__tmp_reg__, Z+
 	lpm	r31, Z
 	mov	r30, __tmp_reg__
+
+#if defined (__AVR_HAVE_EIJMP_EICALL__)
+	eijmp
+#else
 	ijmp
+#endif
+
 #else
 	lpm
 	adiw	r30, 1
 	push	r0
 	lpm
 	push	r0
+#if defined (__AVR_HAVE_EIJMP_EICALL__)
+        push    __zero_reg__
+#endif
 	ret
 #endif
 	.endfunc
Index: gcc/config/avr/avr.md
===================================================================
--- gcc/config/avr/avr.md	(revision 132252)
+++ gcc/config/avr/avr.md	(working copy)
@@ -32,6 +32,7 @@
 ;;  p  POST_INC or PRE_DEC address as a pointer (X, Y, Z)
 ;;  r  POST_INC or PRE_DEC address as a register (r26, r28, r30)
 ;;  ~  Output 'r' if not AVR_MEGA.
+;;  !  Output 'e' if AVR_HAVE_EIJMP_EICALL.
 
 ;; UNSPEC usage:
 ;;  0  Length of a string, see "strlenhi".
@@ -2301,22 +2302,22 @@
   "(register_operand (operands[0], HImode) || CONSTANT_P (operands[0]))"
   "*{
   if (which_alternative==0)
-     return \"icall\";
+     return \"%!icall\";
   else if (which_alternative==1)
     {
       if (AVR_HAVE_MOVW)
 	return (AS2 (movw, r30, %0) CR_TAB
-		\"icall\");
+               \"%!icall\");
       else
 	return (AS2 (mov, r30, %A0) CR_TAB
 		AS2 (mov, r31, %B0) CR_TAB
-		\"icall\");
+		\"%!icall\");
     }
   else if (which_alternative==2)
     return AS1(%~call,%c0);
   return (AS2 (ldi,r30,lo8(%0)) CR_TAB
           AS2 (ldi,r31,hi8(%0)) CR_TAB
-          \"icall\");
+          \"%!icall\");
 }"
   [(set_attr "cc" "clobber,clobber,clobber,clobber")
    (set_attr_alternative "length"
@@ -2338,22 +2339,22 @@
   "(register_operand (operands[0], VOIDmode) || CONSTANT_P (operands[0]))"
   "*{
   if (which_alternative==0)
-     return \"icall\";
+     return \"%!icall\";
   else if (which_alternative==1)
     {
       if (AVR_HAVE_MOVW)
 	return (AS2 (movw, r30, %1) CR_TAB
-		\"icall\");
+		\"%!icall\");
       else
 	return (AS2 (mov, r30, %A1) CR_TAB
 		AS2 (mov, r31, %B1) CR_TAB
-		\"icall\");
+		\"%!icall\");
     }
   else if (which_alternative==2)
     return AS1(%~call,%c1);
   return (AS2 (ldi, r30, lo8(%1)) CR_TAB
           AS2 (ldi, r31, hi8(%1)) CR_TAB
-          \"icall\");
+          \"%!icall\");
 }"
   [(set_attr "cc" "clobber,clobber,clobber,clobber")
    (set_attr_alternative "length"
@@ -2376,13 +2377,20 @@
 ; indirect jump
 (define_insn "indirect_jump"
   [(set (pc) (match_operand:HI 0 "register_operand" "!z,*r"))]
-  ""
+  "!AVR_HAVE_EIJMP_EICALL"
   "@
 	ijmp
 	push %A0\;push %B0\;ret"
   [(set_attr "length" "1,3")
    (set_attr "cc" "none,none")])
 
+(define_insn "*indirect_jump_avr6"
+  [(set (pc) (match_operand:HI 0 "register_operand" "z"))]
+  "AVR_HAVE_EIJMP_EICALL"
+  "eijmp"
+  [(set_attr "length" "1")
+   (set_attr "cc" "none")])
+
 ;; table jump
 
 ;; Table made from "rjmp" instructions for <=8K devices.
@@ -2391,7 +2399,7 @@
 			UNSPEC_INDEX_JMP))
    (use (label_ref (match_operand 1 "" "")))
    (clobber (match_dup 0))]
-  "!AVR_MEGA"
+  "(!AVR_MEGA) && (!AVR_HAVE_EIJMP_EICALL)"
   "@
 	ijmp
 	push %A0\;push %B0\;ret"
@@ -2420,7 +2428,7 @@
 	lpm __tmp_reg__,Z+
 	lpm r31,Z
 	mov r30,__tmp_reg__
-	ijmp"
+	%!ijmp"
   [(set_attr "length" "6")
    (set_attr "cc" "clobber")])
 
@@ -2429,7 +2437,7 @@
 			UNSPEC_INDEX_JMP))
    (use (label_ref (match_operand 1 "" "")))
    (clobber (match_dup 0))]
-  "AVR_MEGA"
+  "AVR_MEGA && !AVR_HAVE_EIJMP_EICALL"
   "lsl r30
 	rol r31
 	lpm
@@ -2764,8 +2764,8 @@
    (use (reg:HI REG_X))
    (clobber (reg:HI REG_Z))]
   ""
-  "ldi r30,pm_lo8(1f)
-	ldi r31,pm_hi8(1f)
+  "ldi r30,lo8(gs(1f))
+	ldi r31,hi8(gs(1f))
 	%~jmp __prologue_saves__+((18 - %0) * 2)
 1:"
   [(set_attr_alternative "length"
Index: gcc/config/avr/avr.c
===================================================================
--- gcc/config/avr/avr.c	(revision 132252)
+++ gcc/config/avr/avr.c	(working copy)
@@ -127,7 +127,8 @@
   { 0, 0, 1, 1, 0, 0, 0, 0, "__AVR_ARCH__=35"  },
   { 0, 1, 0, 1, 0, 0, 0, 0, "__AVR_ARCH__=4"   },
   { 0, 1, 1, 1, 0, 0, 0, 0, "__AVR_ARCH__=5"   },
-  { 0, 1, 1, 1, 1, 1, 0, 0, "__AVR_ARCH__=51"  }
+  { 0, 1, 1, 1, 1, 1, 0, 0, "__AVR_ARCH__=51"  },
+  { 0, 1, 1, 1, 1, 1, 1, 0, "__AVR_ARCH__=6"   }
 };
 
 /* These names are used as the index into the avr_arch_types[] table 
@@ -144,7 +145,8 @@
   ARCH_AVR35,
   ARCH_AVR4,
   ARCH_AVR5,
-  ARCH_AVR51
+  ARCH_AVR51,
+  ARCH_AVR6
 };
 
 struct mcu_type_s {
@@ -273,6 +275,10 @@
   { "at90can128",   ARCH_AVR51, "__AVR_AT90CAN128__" },
   { "at90usb1286",  ARCH_AVR51, "__AVR_AT90USB1286__" },
   { "at90usb1287",  ARCH_AVR51, "__AVR_AT90USB1287__" },
+    /* 3-Byte PC.  */
+  { "avr6",         ARCH_AVR6, NULL },
+  { "atmega2560",   ARCH_AVR6, "__AVR_ATmega2560__" },
+  { "atmega2561",   ARCH_AVR6, "__AVR_ATmega2561__" },
     /* Assembler only.  */
   { "avr1",         ARCH_AVR1, NULL },
   { "at90s1200",    ARCH_AVR1, "__AVR_AT90S1200__" },
@@ -511,9 +517,10 @@
   else
     {
       int offset = frame_pointer_needed ? 2 : 0;
+      int avr_pc_size = AVR_HAVE_EIJMP_EICALL ? 3 : 2;
 
       offset += avr_regs_to_save (NULL);
-      return get_frame_size () + 2 + 1 + offset;
+      return get_frame_size () + (avr_pc_size) + 1 + offset;
     }
 }
 
@@ -682,7 +694,9 @@
       /* Prevent any attempt to delete the setting of ZERO_REG!  */
       emit_insn (gen_rtx_USE (VOIDmode, zero_reg_rtx));
     }
-  if (minimize && (frame_pointer_needed || live_seq > 6)) 
+  if (minimize && (frame_pointer_needed 
+                  || (AVR_2_BYTE_PC && live_seq > 6)
+                  || live_seq > 7)) 
     {
       insn = emit_move_insn (gen_rtx_REG (HImode, REG_X), 
                              gen_int_mode (size, HImode));
@@ -1119,7 +1126,7 @@
 	  && ((GET_CODE (addr) == SYMBOL_REF && SYMBOL_REF_FUNCTION_P (addr))
 	      || GET_CODE (addr) == LABEL_REF))
 	{
-	  fprintf (file, "pm(");
+	  fprintf (file, "gs(");
 	  output_addr_const (file,addr);
 	  fprintf (file ,")");
 	}
@@ -1144,6 +1151,11 @@
       if (!AVR_MEGA)
 	fputc ('r', file);
     }
+  else if (code == '!')
+    {
+      if (AVR_HAVE_EIJMP_EICALL)
+	fputc ('e', file);
+    }
   else if (REG_P (x))
     {
       if (x == zero_reg_rtx)
@@ -4468,7 +4480,7 @@
       && ((GET_CODE (x) == SYMBOL_REF && SYMBOL_REF_FUNCTION_P (x))
 	  || GET_CODE (x) == LABEL_REF))
     {
-      fputs ("\t.word\tpm(", asm_out_file);
+      fputs ("\t.word\tgs(", asm_out_file);
       output_addr_const (asm_out_file, x);
       fputs (")\n", asm_out_file);
       return true;
@@ -5815,7 +5827,7 @@
 {
   switch_to_section (progmem_section);
   if (AVR_MEGA)
-    fprintf (stream, "\t.word pm(.L%d)\n", value);
+    fprintf (stream, "\t.word gs(.L%d)\n", value);
   else
     fprintf (stream, "\trjmp .L%d\n", value);
 }
Index: gcc/config/avr/t-avr
===================================================================
--- gcc/config/avr/t-avr	(revision 132252)
+++ gcc/config/avr/t-avr	(working copy)
@@ -37,8 +37,8 @@
 
 FPBIT = fp-bit.c
 
-MULTILIB_OPTIONS = mmcu=avr2/mmcu=avr25/mmcu=avr3/mmcu=avr31/mmcu=avr35/mmcu=avr4/mmcu=avr5/mmcu=avr51
-MULTILIB_DIRNAMES = avr2 avr25 avr3 avr31 avr35 avr4 avr5 avr51
+MULTILIB_OPTIONS = mmcu=avr2/mmcu=avr25/mmcu=avr3/mmcu=avr31/mmcu=avr35/mmcu=avr4/mmcu=avr5/mmcu=avr51/mmcu=avr6
+MULTILIB_DIRNAMES = avr2 avr25 avr3 avr31 avr35 avr4 avr5 avr51 avr6
 
 # The many avr2 matches are not listed here - this is the default.
 MULTILIB_MATCHES = \
@@ -123,7 +123,9 @@
 	mmcu?avr51=mmcu?atmega1284p \
 	mmcu?avr51=mmcu?at90can128 \
 	mmcu?avr51=mmcu?at90usb1286 \
-	mmcu?avr51=mmcu?at90usb1287
+	mmcu?avr51=mmcu?at90usb1287 \
+ 	mmcu?avr6=mmcu?atmega2560 \
+ 	mmcu?avr6=mmcu?atmega2561
 
 MULTILIB_EXCEPTIONS =
 
Index: gcc/config/avr/avr.h
===================================================================
--- gcc/config/avr/avr.h	(revision 132252)
+++ gcc/config/avr/avr.h	(working copy)
@@ -80,6 +80,12 @@
 	builtin_define ("__AVR_MEGA__");	\
       if (avr_current_arch->have_jmp_call)	\
 	builtin_define ("__AVR_HAVE_JMP_CALL__"); \
+      if (!avr_current_arch->have_eijmp_eicall)	\
+	builtin_define ("__AVR_2_BYTE_PC__");	\
+      if (avr_current_arch->have_eijmp_eicall)	\
+	builtin_define ("__AVR_3_BYTE_PC__");	\
+      if (avr_current_arch->have_eijmp_eicall)	\
+	builtin_define ("__AVR_HAVE_EIJMP_EICALL__"); \
       if (TARGET_NO_INTERRUPTS)			\
 	builtin_define ("__NO_INTERRUPTS__");	\
     }						\
@@ -100,9 +106,10 @@
 #define AVR_HAVE_MOVW (avr_have_movw_lpmx_p)
 #define AVR_HAVE_LPMX (avr_have_movw_lpmx_p)
 #define AVR_HAVE_RAMPZ (avr_current_arch->have_elpm)
+#define AVR_HAVE_EIJMP_EICALL (avr_current_arch->have_eijmp_eicall)
 
-#define AVR_2_BYTE_PC 1
-#define AVR_3_BYTE_PC 0
+#define AVR_2_BYTE_PC (!AVR_HAVE_EIJMP_EICALL)
+#define AVR_3_BYTE_PC (AVR_HAVE_EIJMP_EICALL)
 
 #define TARGET_VERSION fprintf (stderr, " (GNU assembler syntax)");
 
@@ -671,7 +678,7 @@
 
 #define PRINT_OPERAND(STREAM, X, CODE) print_operand (STREAM, X, CODE)
 
-#define PRINT_OPERAND_PUNCT_VALID_P(CODE) ((CODE) == '~')
+#define PRINT_OPERAND_PUNCT_VALID_P(CODE) ((CODE) == '~' || (CODE) == '!')
 
 #define PRINT_OPERAND_ADDRESS(STREAM, X) print_operand_address(STREAM, X)
 
@@ -828,6 +835,7 @@
   mmcu=at90usb64*|\
   mmcu=at90usb128*|\
   mmcu=at94k: -m avr5}\
+%{mmcu=atmega256*:-m avr6}\
 %{mmcu=atmega324*|\
   mmcu=atmega325*|\
   mmcu=atmega328p|\
@@ -856,7 +864,8 @@
   mmcu=at90usb*: -Tdata 0x800100}\
 %{mmcu=atmega640|\
   mmcu=atmega1280|\
-  mmcu=atmega1281: -Tdata 0x800200} "
+  mmcu=atmega1281|\
+  mmcu=atmega256*: -Tdata 0x800200} "
 
 #define LIB_SPEC \
   "%{!mmcu=at90s1*:%{!mmcu=attiny11:%{!mmcu=attiny12:%{!mmcu=attiny15:%{!mmcu=attiny28: -lc }}}}}"
@@ -968,6 +977,8 @@
 %{mmcu=atmega1280:crtm1280.o%s} \
 %{mmcu=atmega1281:crtm1281.o%s} \
 %{mmcu=atmega1284p:crtm1284p.o%s} \
+%{mmcu=atmega2560:crtm2560.o%s} \
+%{mmcu=atmega2561:crtm2561.o%s} \
 %{mmcu=at90can128:crtcan128.o%s} \
 %{mmcu=at90usb1286:crtusb1286.o%s} \
 %{mmcu=at90usb1287:crtusb1287.o%s}"
