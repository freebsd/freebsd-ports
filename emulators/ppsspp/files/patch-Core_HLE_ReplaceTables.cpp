--- Core/HLE/ReplaceTables.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/HLE/ReplaceTables.cpp
@@ -1007,6 +1007,8 @@ static int Hook_photokano_download_frame
 #define JITFUNC(f) (&MIPSComp::Jit::f)
 #elif defined(MIPS)
 #define JITFUNC(f) (&MIPSComp::Jit::f)
+#else
+#define JITFUNC(f) (&MIPSComp::FakeJit::f)
 #endif
 
 // Can either replace with C functions or functions emitted in Asm/ArmAsm.
