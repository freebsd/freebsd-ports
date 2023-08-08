--- v8/src/wasm/baseline/ia32/liftoff-assembler-ia32.h.orig	2023-02-01 18:45:24 UTC
+++ v8/src/wasm/baseline/ia32/liftoff-assembler-ia32.h
@@ -448,7 +448,7 @@ void LiftoffAssembler::StoreTaggedPointer(Register dst
 }
 
 void LiftoffAssembler::Load(LiftoffRegister dst, Register src_addr,
-                            Register offset_reg, uint32_t offset_imm,
+                            Register offset_reg, uintptr_t offset_imm,
                             LoadType type, uint32_t* protected_load_pc,
                             bool /* is_load_mem */, bool i64_offset,
                             bool needs_shift) {
@@ -528,7 +528,7 @@ void LiftoffAssembler::Load(LiftoffRegister dst, Regis
 }
 
 void LiftoffAssembler::Store(Register dst_addr, Register offset_reg,
-                             uint32_t offset_imm, LiftoffRegister src,
+                             uintptr_t offset_imm, LiftoffRegister src,
                              StoreType type, LiftoffRegList pinned,
                              uint32_t* protected_store_pc,
                              bool /* is_store_mem */, bool /* i64_offset */) {
@@ -597,7 +597,7 @@ void LiftoffAssembler::Store(Register dst_addr, Regist
 }
 
 void LiftoffAssembler::AtomicLoad(LiftoffRegister dst, Register src_addr,
-                                  Register offset_reg, uint32_t offset_imm,
+                                  Register offset_reg, uintptr_t offset_imm,
                                   LoadType type, LiftoffRegList /* pinned */) {
   if (type.value() != LoadType::kI64Load) {
     Load(dst, src_addr, offset_reg, offset_imm, type, nullptr, true);
@@ -616,7 +616,7 @@ void LiftoffAssembler::AtomicLoad(LiftoffRegister dst,
 }
 
 void LiftoffAssembler::AtomicStore(Register dst_addr, Register offset_reg,
-                                   uint32_t offset_imm, LiftoffRegister src,
+                                   uintptr_t offset_imm, LiftoffRegister src,
                                    StoreType type, LiftoffRegList pinned) {
   DCHECK_NE(offset_reg, no_reg);
   DCHECK_LE(offset_imm, std::numeric_limits<int32_t>::max());
@@ -956,7 +956,7 @@ inline void AtomicBinop64(LiftoffAssembler* lasm, Bino
 }  // namespace liftoff
 
 void LiftoffAssembler::AtomicAdd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kAdd, dst_addr, offset_reg,
@@ -969,7 +969,7 @@ void LiftoffAssembler::AtomicAdd(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicSub(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kSub, dst_addr, offset_reg,
@@ -981,7 +981,7 @@ void LiftoffAssembler::AtomicSub(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicAnd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kAnd, dst_addr, offset_reg,
@@ -994,7 +994,7 @@ void LiftoffAssembler::AtomicAnd(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicOr(Register dst_addr, Register offset_reg,
-                                uint32_t offset_imm, LiftoffRegister value,
+                                uintptr_t offset_imm, LiftoffRegister value,
                                 LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kOr, dst_addr, offset_reg, offset_imm,
@@ -1007,7 +1007,7 @@ void LiftoffAssembler::AtomicOr(Register dst_addr, Reg
 }
 
 void LiftoffAssembler::AtomicXor(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kXor, dst_addr, offset_reg,
@@ -1020,7 +1020,7 @@ void LiftoffAssembler::AtomicXor(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicExchange(Register dst_addr, Register offset_reg,
-                                      uint32_t offset_imm,
+                                      uintptr_t offset_imm,
                                       LiftoffRegister value,
                                       LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
@@ -1034,7 +1034,7 @@ void LiftoffAssembler::AtomicExchange(Register dst_add
 }
 
 void LiftoffAssembler::AtomicCompareExchange(
-    Register dst_addr, Register offset_reg, uint32_t offset_imm,
+    Register dst_addr, Register offset_reg, uintptr_t offset_imm,
     LiftoffRegister expected, LiftoffRegister new_value, LiftoffRegister result,
     StoreType type) {
   // We expect that the offset has already been added to {dst_addr}, and no
