
$FreeBSD$

--- mono/mini/mini-x86.c.orig
+++ mono/mini/mini-x86.c
@@ -1068,26 +1068,15 @@
 	}
 
 	if (sig->ret && MONO_TYPE_ISSTRUCT (sig->ret)) {
-		MonoInst *vtarg;
-
 		if (cinfo->ret.storage == ArgValuetypeInReg) {
-			if (cinfo->ret.pair_storage [0] == ArgInIReg && cinfo->ret.pair_storage [1] == ArgNone) {
 				/*
 				 * Tell the JIT to use a more efficient calling convention: call using
 				 * OP_CALL, compute the result location after the call, and save the 
 				 * result there.
 				 */
 				call->vret_in_reg = TRUE;
-			} else {
-				/*
-				 * The valuetype is in EAX:EDX after the call, needs to be copied to
-				 * the stack. Save the address here, so the call instruction can
-				 * access it.
-				 */
-				MONO_INST_NEW (cfg, vtarg, OP_X86_PUSH);
-				vtarg->sreg1 = call->vret_var->dreg;
-				MONO_ADD_INS (cfg->cbb, vtarg);
-			}
+				if (call->vret_var)
+					NULLIFY_INS (call->vret_var);
 		}
 	}
 
@@ -1802,9 +1791,6 @@
 static guint8*
 emit_move_return_value (MonoCompile *cfg, MonoInst *ins, guint8 *code)
 {
-	CallInfo *cinfo;
-	int quad;
-
 	/* Move return value to the target register */
 	switch (ins->opcode) {
 	case OP_CALL:
@@ -1813,31 +1799,6 @@
 		if (ins->dreg != X86_EAX)
 			x86_mov_reg_reg (code, ins->dreg, X86_EAX, 4);
 		break;
-	case OP_VCALL:
-	case OP_VCALL_REG:
-	case OP_VCALL_MEMBASE:
-	case OP_VCALL2:
-	case OP_VCALL2_REG:
-	case OP_VCALL2_MEMBASE:
-		cinfo = get_call_info (cfg->generic_sharing_context, cfg->mempool, ((MonoCallInst*)ins)->signature, FALSE);
-		if (cinfo->ret.storage == ArgValuetypeInReg) {
-			/* Pop the destination address from the stack */
-			x86_pop_reg (code, X86_ECX);
-			
-			for (quad = 0; quad < 2; quad ++) {
-				switch (cinfo->ret.pair_storage [quad]) {
-				case ArgInIReg:
-					g_assert (cinfo->ret.pair_regs [quad] != X86_ECX);
-					x86_mov_membase_reg (code, X86_ECX, (quad * sizeof (gpointer)), cinfo->ret.pair_regs [quad], sizeof (gpointer));
-					break;
-				case ArgNone:
-					break;
-				default:
-					g_assert_not_reached ();
-				}
-			}
-		}
-		break;
 	case OP_FCALL: {
 		MonoCallInst *call = (MonoCallInst*)ins;
 		if (call->method && !mono_method_signature (call->method)->ret->byref && mono_method_signature (call->method)->ret->type == MONO_TYPE_R4) {
