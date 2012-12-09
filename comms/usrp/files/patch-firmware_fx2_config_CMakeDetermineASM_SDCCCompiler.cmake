--- firmware/fx2/config/CMakeDetermineASM_SDCCCompiler.cmake.orig	2012-10-06 17:31:51.000000000 -0500
+++ firmware/fx2/config/CMakeDetermineASM_SDCCCompiler.cmake	2012-10-09 07:09:09.000000000 -0500
@@ -16,7 +16,6 @@
 
 SET(ASM_DIALECT "_SDCC")
 
-SET(CMAKE_ASM${ASM_DIALECT}_COMPILER_INIT asx8051)
+SET(CMAKE_ASM${ASM_DIALECT}_COMPILER_INIT mcs51)
 
 INCLUDE(CMakeDetermineASMCompiler)
-SET(ASM_DIALECT)
