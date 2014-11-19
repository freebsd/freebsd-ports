--- src/qml/jit/qv4assembler.cpp
+++ src/qml/jit/qv4assembler.cpp
@@ -96,7 +96,7 @@ QV4::ExecutableAllocator::ChunkOfPages *CompilationUnit::chunkForFunction(int fu
 /* Platform/Calling convention/Architecture specific section */
 
 #if CPU(X86_64)
-#  if OS(LINUX) || OS(MAC_OS_X)
+#  if OS(UNIX)
 static const Assembler::RegisterID calleeSavedRegisters[] = {
     JSC::X86Registers::ebx,
     JSC::X86Registers::r12, // LocalsRegister
