--- v8/src/wasm/jump-table-assembler.cc.orig	2023-11-29 21:41:54 UTC
+++ v8/src/wasm/jump-table-assembler.cc
@@ -74,15 +74,21 @@ void JumpTableAssembler::EmitLazyCompileJumpSlot(uint3
 #if V8_TARGET_ARCH_X64
 void JumpTableAssembler::EmitLazyCompileJumpSlot(uint32_t func_index,
                                                  Address lazy_compile_target) {
+  intptr_t displacement =
+      static_cast<intptr_t>(reinterpret_cast<uint8_t*>(lazy_compile_target) -
+                            (pc_ + 9) - kNearJmpInstrSize);
+  if (!is_int32(displacement)) return;
+  CodeEntry();  // 4 bytes
   // Use a push, because mov to an extended register takes 6 bytes.
-  pushq_imm32(func_index);            // 5 bytes
-  EmitJumpSlot(lazy_compile_target);  // 5 bytes
+  pushq_imm32(func_index);                     // 5 bytes
+  near_jmp(displacement, RelocInfo::NO_INFO);  // 5 bytes
 }
 
 bool JumpTableAssembler::EmitJumpSlot(Address target) {
   intptr_t displacement = static_cast<intptr_t>(
-      reinterpret_cast<uint8_t*>(target) - pc_ - kNearJmpInstrSize);
+      reinterpret_cast<uint8_t*>(target) - (pc_ + 4) - kNearJmpInstrSize);
   if (!is_int32(displacement)) return false;
+  CodeEntry();                                 // 4 bytes
   near_jmp(displacement, RelocInfo::NO_INFO);  // 5 bytes
   return true;
 }
@@ -90,11 +96,12 @@ void JumpTableAssembler::EmitFarJumpSlot(Address targe
 void JumpTableAssembler::EmitFarJumpSlot(Address target) {
   Label data;
   int start_offset = pc_offset();
+  CodeEntry();          // 4 bytes
   jmp(Operand(&data));  // 6 bytes
-  Nop(2);               // 2 bytes
+  Nop(6);               // 6 bytes
   // The data must be properly aligned, so it can be patched atomically (see
   // {PatchFarJumpSlot}).
-  DCHECK_EQ(start_offset + kSystemPointerSize, pc_offset());
+  DCHECK_EQ(start_offset + kFarJumpTableSlotOffset, pc_offset());
   USE(start_offset);
   bind(&data);
   dq(target);  // 8 bytes
@@ -105,7 +112,7 @@ void JumpTableAssembler::PatchFarJumpSlot(Address slot
   // The slot needs to be pointer-size aligned so we can atomically update it.
   DCHECK(IsAligned(slot, kSystemPointerSize));
   // Offset of the target is at 8 bytes, see {EmitFarJumpSlot}.
-  reinterpret_cast<std::atomic<Address>*>(slot + kSystemPointerSize)
+  reinterpret_cast<std::atomic<Address>*>(slot + kFarJumpTableSlotOffset)
       ->store(target, std::memory_order_relaxed);
   // The update is atomic because the address is properly aligned.
   // Because of cache coherence, the data update will eventually be seen by all
