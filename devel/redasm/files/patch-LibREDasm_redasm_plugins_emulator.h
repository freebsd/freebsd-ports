--- LibREDasm/redasm/plugins/emulator.h.orig	2019-05-23 14:58:04 UTC
+++ LibREDasm/redasm/plugins/emulator.h
@@ -28,11 +28,7 @@ class Emulator
         MemoryBuffer* getSegmentMemory(address_t address, offset_t* offset);
         BufferView getMemory(address_t address);
         BufferView getStack(offset_t sp);
-
-    private:
         void remap();
-
-    protected:
         InstructionPtr m_currentinstruction;
         DisassemblerAPI* m_disassembler;
         DispatcherType m_dispatcher;
