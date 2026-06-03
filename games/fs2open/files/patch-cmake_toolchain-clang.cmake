--- cmake/toolchain-clang.cmake.orig	2026-02-10 10:48:25 UTC
+++ cmake/toolchain-clang.cmake
@@ -15,7 +15,7 @@ if(IS_X86)
 
 if(IS_X86)
 	if(FORCED_NATIVE_SIMD_INSTRUCTIONS)
-		set(CLANG_EXTENSIONS "-march=native")
+		set(CLANG_EXTENSIONS "")
 	elseif (FSO_INSTRUCTION_SET STREQUAL "")
 		set(CLANG_EXTENSIONS "-march=x86-64")
 	elseif (FSO_INSTRUCTION_SET STREQUAL "SSE")
@@ -34,8 +34,8 @@ elseif(IS_ARM)
 	set(CXX_BASE_FLAGS "${CXX_BASE_FLAGS} ${CLANG_EXTENSIONS}")
 elseif(IS_ARM)
 	if(FORCED_NATIVE_SIMD_INSTRUCTIONS)
-		set(C_BASE_FLAGS "${C_BASE_FLAGS} -march=native")
-		set(CXX_BASE_FLAGS "${CXX_BASE_FLAGS} -march=native")
+		set(C_BASE_FLAGS "${C_BASE_FLAGS}")
+		set(CXX_BASE_FLAGS "${CXX_BASE_FLAGS}")
     endif ()
 elseif(IS_RISCV)
     # Default C/CXX_BASE_FLAGS are fine for RISC-V
