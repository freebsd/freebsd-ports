--- objc_msgSend.powerpc64.S.orig	2026-06-08 11:30:27 UTC
+++ objc_msgSend.powerpc64.S
@@ -0,0 +1,298 @@
+/* objc_msgSend.powerpc64.S - PowerPC64 ELFv2 fast-path dispatch for GNUstep libobjc2.
+ *
+ * Included from objc_msgSend.S after common.S and asmconstants.h.
+ * Works for both ppc64le (LE) and ppc64 BE with the ELFv2 ABI.
+ *
+ * Dispatch overview:
+ *   Fast path (no frame): nil-check → small-obj-check → isa → dtable lookup → IMP → bctr
+ *   Slow path (frame + spill): for nil slots (cache miss), calls slowMsgLookup
+ *
+ * ELFv2 frame layout used on the slow path (FRAME_SIZE = 208):
+ *   +0   back chain   +8  CR save   +24  TOC (r2)
+ *   +32  r3  +40  r4  +48  r5  +56  r6  +64  r7  +72  r8  +80  r9  +88  r10
+ *   +96  f1  ...  +192  f13
+ *   LR saved at (FRAME_SIZE+16)(r1) = old_sp+16 per ELFv2 convention.
+ */
+
+#define FRAME_SIZE 208
+
+.globl CDECL(objc_msgSend)
+TYPE_DIRECTIVE(CDECL(objc_msgSend), %function)
+.globl CDECL(objc_msgSend_fpret)
+TYPE_DIRECTIVE(CDECL(objc_msgSend_fpret), %function)
+
+CDECL(objc_msgSend_fpret):
+CDECL(objc_msgSend):
+.Lgep_objc_msgSend:
+	.cfi_startproc
+	addis	2, 12, .TOC.-.Lgep_objc_msgSend@ha
+	addi	2, 2, .TOC.-.Lgep_objc_msgSend@l
+.localentry CDECL(objc_msgSend), .-.Lgep_objc_msgSend
+
+	/* Nil receiver */
+	cmpdi	cr0, 3, 0
+	beq-	cr0, .Lnil_msgSend
+
+	/* Small-object check: r3 & SMALLOBJ_MASK → r11, sets CR0 */
+	andi.	11, 3, SMALLOBJ_MASK
+	bne-	cr0, .Lsmall_msgSend
+
+	/* Load isa from normal receiver */
+	ld	11, 0(3)
+
+.LclassLoaded:
+	/* dtable → r11; sel->index (uint32_t) → r12; dtable->shift → r0 */
+	ld	11, DTABLE_OFFSET(11)
+	lwz	12, 0(4)
+	lwz	0, SHIFT_OFFSET(11)
+
+	/* Three-level sparse-array lookup.
+	 * Each rlwinm extracts one byte of the selector index and scales by 8.
+	 * shift=0: single level (8-bit);  shift=8: two levels (16-bit);
+	 * anything else: three levels (24-bit, the common case). */
+	cmpwi	cr0, 0, 8
+	beq-	cr0, .Ldtable16
+	cmpwi	cr0, 0, 0
+	beq-	cr0, .Ldtable8
+
+	/* Level 1: bits [23:16] of index, scaled by 8 */
+	rlwinm	0, 12, 19, 21, 28		/* r0 = (index >> 16 & 0xFF) << 3 */
+	add	11, 11, 0			/* r11 = dtable + offset (r0 can't be mem base) */
+	ld	11, DATA_OFFSET(11)
+
+.Ldtable16:
+	/* Level 2: bits [15:8] */
+	rlwinm	0, 12, 27, 21, 28		/* r0 = (index >> 8 & 0xFF) << 3 */
+	add	11, 11, 0
+	ld	11, DATA_OFFSET(11)
+
+.Ldtable8:
+	/* Level 3: bits [7:0] → slot pointer */
+	rlwinm	0, 12, 3, 21, 28		/* r0 = (index & 0xFF) << 3 */
+	add	11, 11, 0
+	ld	11, DATA_OFFSET(11)
+
+	cmpdi	cr0, 11, 0
+	beq-	cr0, .Lslow_msgSend
+
+	/* Load IMP from slot, tail-call (r12 = entry for ELFv2 global-entry TOC setup) */
+	ld	12, SLOT_OFFSET(11)
+	mtctr	12
+	bctr
+
+.Lnil_msgSend:
+	/* Nil receiver: zero integer (r3:r4) and FP (f1:f2) return registers.
+	 * objc_msgSend_fpret shares this entry, so a nil send returning
+	 * float/double must yield 0.0 — clear f1:f2 via the ELFv2 red zone. */
+	li	3, 0
+	li	4, 0
+	std	3, -8(1)
+	lfd	1, -8(1)
+	lfd	2, -8(1)
+	blr
+
+.Lslow_msgSend:
+	/* Slow path: spill all argument registers around the lookup call.
+	 * CFI lets exceptions from +initialize (run inside slowMsgLookup)
+	 * unwind through this frame. */
+	.cfi_remember_state
+	mflr	0
+	stdu	1, -FRAME_SIZE(1)
+	.cfi_def_cfa_offset FRAME_SIZE
+	std	0, (FRAME_SIZE + 16)(1)
+	.cfi_offset 65, 16
+	std	2, 24(1)
+	std	3, 32(1)			/* self at +32; &self = r1+32 for slowMsgLookup */
+	std	4, 40(1)
+	std	5, 48(1)
+	std	6, 56(1)
+	std	7, 64(1)
+	std	8, 72(1)
+	std	9, 80(1)
+	std	10, 88(1)
+	stfd	1,  96(1)
+	stfd	2,  104(1)
+	stfd	3,  112(1)
+	stfd	4,  120(1)
+	stfd	5,  128(1)
+	stfd	6,  136(1)
+	stfd	7,  144(1)
+	stfd	8,  152(1)
+	stfd	9,  160(1)
+	stfd	10, 168(1)
+	stfd	11, 176(1)
+	stfd	12, 184(1)
+	stfd	13, 192(1)
+
+	/* slowMsgLookup(id *receiver, SEL cmd) — may modify *receiver for forwarding */
+	addi	3, 1, 32
+	/* r4 = sel (already set) */
+	bl	CDECL(slowMsgLookup)
+	nop					/* linker patches to: ld 2, 24(1) */
+
+	mr	12, 3
+	ld	3, 32(1)			/* reload (possibly-modified) self */
+	ld	4, 40(1)
+	ld	5, 48(1)
+	ld	6, 56(1)
+	ld	7, 64(1)
+	ld	8, 72(1)
+	ld	9, 80(1)
+	ld	10, 88(1)
+	lfd	1,  96(1)
+	lfd	2,  104(1)
+	lfd	3,  112(1)
+	lfd	4,  120(1)
+	lfd	5,  128(1)
+	lfd	6,  136(1)
+	lfd	7,  144(1)
+	lfd	8,  152(1)
+	lfd	9,  160(1)
+	lfd	10, 168(1)
+	lfd	11, 176(1)
+	lfd	12, 184(1)
+	lfd	13, 192(1)
+	addi	1, 1, FRAME_SIZE
+	ld	0, 16(1)
+	mtlr	0
+	mtctr	12
+	bctr
+	.cfi_restore_state
+
+.Lsmall_msgSend:
+	/* r11 = receiver & SMALLOBJ_MASK = tag (1-7); look up class in global array */
+	addis	12, 2, CDECL(SmallObjectClasses)@toc@ha
+	addi	12, 12, CDECL(SmallObjectClasses)@toc@l
+	sldi	11, 11, 3			/* tag * 8 (pointer size) */
+	ldx	11, 12, 11			/* r11 = SmallObjectClasses[tag] */
+	b	.LclassLoaded
+
+	.cfi_endproc
+
+
+.globl CDECL(objc_msgSend_stret)
+TYPE_DIRECTIVE(CDECL(objc_msgSend_stret), %function)
+
+/* stret: r3 = hidden struct ptr, r4 = self, r5 = sel */
+CDECL(objc_msgSend_stret):
+.Lgep_objc_msgSend_stret:
+	.cfi_startproc
+	addis	2, 12, .TOC.-.Lgep_objc_msgSend_stret@ha
+	addi	2, 2, .TOC.-.Lgep_objc_msgSend_stret@l
+.localentry CDECL(objc_msgSend_stret), .-.Lgep_objc_msgSend_stret
+
+	cmpdi	cr0, 4, 0
+	beq-	cr0, .Lnil_stret
+
+	andi.	11, 4, SMALLOBJ_MASK
+	bne-	cr0, .Lsmall_stret
+
+	ld	11, 0(4)
+
+.LclassLoaded_stret:
+	ld	11, DTABLE_OFFSET(11)
+	lwz	12, 0(5)			/* sel index from r5 */
+	lwz	0, SHIFT_OFFSET(11)
+
+	cmpwi	cr0, 0, 8
+	beq-	cr0, .Ldtable16_stret
+	cmpwi	cr0, 0, 0
+	beq-	cr0, .Ldtable8_stret
+
+	rlwinm	0, 12, 19, 21, 28
+	add	11, 11, 0
+	ld	11, DATA_OFFSET(11)
+
+.Ldtable16_stret:
+	rlwinm	0, 12, 27, 21, 28
+	add	11, 11, 0
+	ld	11, DATA_OFFSET(11)
+
+.Ldtable8_stret:
+	rlwinm	0, 12, 3, 21, 28
+	add	11, 11, 0
+	ld	11, DATA_OFFSET(11)
+
+	cmpdi	cr0, 11, 0
+	beq-	cr0, .Lslow_stret
+
+	ld	12, SLOT_OFFSET(11)
+	mtctr	12
+	bctr
+
+.Lnil_stret:
+	blr
+
+.Lslow_stret:
+	/* See .Lslow_msgSend for why this frame carries CFI. */
+	.cfi_remember_state
+	mflr	0
+	stdu	1, -FRAME_SIZE(1)
+	.cfi_def_cfa_offset FRAME_SIZE
+	std	0, (FRAME_SIZE + 16)(1)
+	.cfi_offset 65, 16
+	std	2, 24(1)
+	std	3, 32(1)			/* struct ptr */
+	std	4, 40(1)			/* self at +40; &self = r1+40 */
+	std	5, 48(1)			/* sel */
+	std	6, 56(1)
+	std	7, 64(1)
+	std	8, 72(1)
+	std	9, 80(1)
+	std	10, 88(1)
+	stfd	1,  96(1)
+	stfd	2,  104(1)
+	stfd	3,  112(1)
+	stfd	4,  120(1)
+	stfd	5,  128(1)
+	stfd	6,  136(1)
+	stfd	7,  144(1)
+	stfd	8,  152(1)
+	stfd	9,  160(1)
+	stfd	10, 168(1)
+	stfd	11, 176(1)
+	stfd	12, 184(1)
+	stfd	13, 192(1)
+
+	addi	3, 1, 40			/* r3 = &self */
+	mr	4, 5				/* r4 = sel */
+	bl	CDECL(slowMsgLookup)
+	nop
+
+	mr	12, 3
+	ld	3, 32(1)
+	ld	4, 40(1)			/* reload (possibly-modified) self */
+	ld	5, 48(1)
+	ld	6, 56(1)
+	ld	7, 64(1)
+	ld	8, 72(1)
+	ld	9, 80(1)
+	ld	10, 88(1)
+	lfd	1,  96(1)
+	lfd	2,  104(1)
+	lfd	3,  112(1)
+	lfd	4,  120(1)
+	lfd	5,  128(1)
+	lfd	6,  136(1)
+	lfd	7,  144(1)
+	lfd	8,  152(1)
+	lfd	9,  160(1)
+	lfd	10, 168(1)
+	lfd	11, 176(1)
+	lfd	12, 184(1)
+	lfd	13, 192(1)
+	addi	1, 1, FRAME_SIZE
+	ld	0, 16(1)
+	mtlr	0
+	mtctr	12
+	bctr
+	.cfi_restore_state
+
+.Lsmall_stret:
+	addis	12, 2, CDECL(SmallObjectClasses)@toc@ha
+	addi	12, 12, CDECL(SmallObjectClasses)@toc@l
+	sldi	11, 11, 3
+	ldx	11, 12, 11
+	b	.LclassLoaded_stret
+
+	.cfi_endproc
