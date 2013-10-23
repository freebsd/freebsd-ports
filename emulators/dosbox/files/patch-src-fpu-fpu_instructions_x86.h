Index: src/fpu/fpu_instructions_x86.h
@@ -1162,12 +1162,12 @@
 
 static void FPU_FLD_I16(PhysPt addr,Bitu store_to) {
 	fpu.p_regs[8].m1 = (Bit32u)mem_readw(addr);
-	FPUD_LOAD(fild,WORD,)
+	FPUD_LOAD(fild,WORD,s)
 }
 
 static void FPU_FLD_I16_EA(PhysPt addr) {
 	fpu.p_regs[8].m1 = (Bit32u)mem_readw(addr);
-	FPUD_LOAD_EA(fild,WORD,)
+	FPUD_LOAD_EA(fild,WORD,s)
 }
 
 static void FPU_FLD_I32(PhysPt addr,Bitu store_to) {
@@ -1212,7 +1212,7 @@
 }
 
 static void FPU_FST_I16(PhysPt addr) {
-	FPUD_STORE(fistp,WORD,)
+	FPUD_STORE(fistp,WORD,s)
 	mem_writew(addr,(Bit16u)fpu.p_regs[8].m1);
 }
