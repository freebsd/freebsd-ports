--- firmware/fx2/config/Toolchain-sdcc.cmake.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/config/Toolchain-sdcc.cmake	2012-10-10 16:22:15.000000000 -0500
@@ -19,9 +19,13 @@
 SET(CMAKE_SYSTEM_NAME Generic)
 # which compilers to use for C and C++
 SET(CMAKE_C_COMPILER sdcc)
+#SET(CMAKE_ASM_SDCC_COMPILER asm)
+SET(CMAKE_ASM_SDCC_COMPILER sdas8051)
+#SET CMAKE_ASM_SDCC_COMPILER
+#SET(CMAKE_ASM_COMPILER sdcc)
 
 # here is where the target environment is located
-SET(CMAKE_FIND_ROOT_PATH  /usr/bin /usr/share/sdcc)
+SET(CMAKE_FIND_ROOT_PATH  /usr/local/bin /usr/local/share/sdcc)
 
 # adjust the default behaviour of the FIND_XXX() commands:
 # search headers and libraries in the target environment, search 
