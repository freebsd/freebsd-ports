--- libswirl/hw/arm7/arm7_jit_virt_x86.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/hw/arm7/arm7_jit_virt_x86.cpp
@@ -11,8 +11,101 @@
 
 #if HOST_CPU == CPU_X86 && FEAT_AREC == DYNAREC_JIT
 
-#if HOST_OS == OS_LINUX || HOST_OS == OS_DARWIN
+#if HOST_OS == OS_LINUX || HOST_OS == OS_DARWIN || HOST_OS == OS_FREEBSD
 #include <sys/mman.h>
+
+#define DP_R_ROFC (OP_READ_FLAGS_S|OP_READ_REG_1) //Reads reg1, op2, flags if S
+#define DP_R_ROF (OP_READ_FLAGS|OP_READ_REG_1)    //Reads reg1, op2, flags (ADC & co)
+#define DP_R_OFC (OP_READ_FLAGS_S)                //Reads op2, flags if S
+
+#define DP_W_RFC (OP_WRITE_FLAGS_S|OP_WRITE_REG)  //Writes reg, and flags if S
+#define DP_W_F (OP_WRITE_FLAGS)                   //Writes only flags, always (S=1)
+
+struct ArmDPOP {
+  u32 key;
+  u32 mask;
+  u32 flags;
+};
+
+vector<ArmDPOP> ops;
+
+void AddDPOP(u32 subcd, u32 rflags, u32 wflags) {
+  ArmDPOP op;
+
+  u32 key = subcd << 21;
+  u32 mask = (15 << 21) | (7 << 25);
+
+  op.flags = rflags | wflags;
+
+  if (wflags == DP_W_F) {
+    //also match S bit for opcodes that must write to flags (CMP & co)
+    mask |= 1 << 20;
+    key |= 1 << 20;
+  }
+
+  //ISR form (bit 25=0, bit 4 = 0)
+  op.key = key;
+  op.mask = mask | (1 << 4);
+  ops.push_back(op);
+
+  //RSR form (bit 25=0, bit 4 = 1, bit 7=0)
+  op.key = key | (1 << 4);
+  op.mask = mask | (1 << 4) | (1 << 7);
+  ops.push_back(op);
+
+  //imm8r4 form (bit 25=1)
+  op.key = key | (1 << 25);
+  op.mask = mask;
+  ops.push_back(op);
+}
+
+void InitHash() {
+  /*
+     COND | 00 I OP1  S Rn Rd OPER2 -- Data opcode, PSR xfer
+     Data processing opcodes
+  */
+
+  //AND   0000        Rn, OPER2, {Flags}    Rd, {Flags}
+  //EOR   0001        Rn, OPER2, {Flags}    Rd, {Flags}
+  //SUB   0010        Rn, OPER2, {Flags}    Rd, {Flags}
+  //RSB   0011        Rn, OPER2, {Flags}    Rd, {Flags}
+  //ADD   0100        Rn, OPER2, {Flags}    Rd, {Flags}
+  //ORR   1100        Rn, OPER2, {Flags}    Rd, {Flags}
+  //BIC   1110        Rn, OPER2, {Flags}    Rd, {Flags}
+  AddDPOP(0, DP_R_ROFC, DP_W_RFC);
+  AddDPOP(1, DP_R_ROFC, DP_W_RFC);
+  AddDPOP(2, DP_R_ROFC, DP_W_RFC);
+  AddDPOP(3, DP_R_ROFC, DP_W_RFC);
+  AddDPOP(4, DP_R_ROFC, DP_W_RFC);
+  AddDPOP(12, DP_R_ROFC, DP_W_RFC);
+  AddDPOP(14, DP_R_ROFC, DP_W_RFC);
+
+  //ADC   0101        Rn, OPER2, Flags      Rd, {Flags}
+  //SBC   0110        Rn, OPER2, Flags      Rd, {Flags}
+  //RSC   0111        Rn, OPER2, Flags      Rd, {Flags}
+  AddDPOP(5, DP_R_ROF, DP_W_RFC);
+  AddDPOP(6, DP_R_ROF, DP_W_RFC);
+  AddDPOP(7, DP_R_ROF, DP_W_RFC);
+
+  //TST   1000 S=1    Rn, OPER2, Flags      Flags
+  //TEQ   1001 S=1    Rn, OPER2, Flags      Flags
+  AddDPOP(8, DP_R_ROF, DP_W_F);
+  AddDPOP(9, DP_R_ROF, DP_W_F);
+
+  //CMP   1010 S=1    Rn, OPER2             Flags
+  //CMN   1011 S=1    Rn, OPER2             Flags
+  AddDPOP(10, DP_R_ROF, DP_W_F);
+  AddDPOP(11, DP_R_ROF, DP_W_F);
+
+  //MOV   1101        OPER2, {Flags}        Rd, {Flags}
+  //MVN   1111        OPER2, {Flags}        Rd, {Flags}
+  AddDPOP(13, DP_R_OFC, DP_W_RFC);
+  AddDPOP(15, DP_R_OFC, DP_W_RFC);
+}
+
+void armt_init() {
+  InitHash();
+}
 #endif
 #if HOST_OS == OS_WINDOWS
 #include <Windows.h>
@@ -55,6 +148,8 @@ u8 ARM7_TCB[ICacheSize + 4096] __attribute__((section(
 
 #elif HOST_OS==OS_DARWIN
 u8 ARM7_TCB[ICacheSize + 4096] __attribute__((section("__TEXT, .text")));
+#elif HOST_OS==OS_FREEBSD
+u8 ARM7_TCB[ICacheSize + 4096] __attribute__((section(".text")));
 #else
 #error ARM7_TCB ALLOC
 #endif
