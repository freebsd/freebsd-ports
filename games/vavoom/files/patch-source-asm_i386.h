--- source/asm_i386.h.orig	Mon Jan 19 09:45:14 2004
+++ source/asm_i386.h	Mon Jan 19 09:46:32 2004
@@ -27,13 +27,13 @@
 
 #define USEASM
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define C(label)	label		//	ELF format
 #else
 #define C(label)	_##label	//	COFF format
 #endif
 
-#if !defined GAS2TASM && (defined DJGPP || defined __linux__)
+#if !defined GAS2TASM && (defined DJGPP || defined __linux__ || defined __FreeBSD__)
 #define Align4		.p2align 2
 #define Align8		.p2align 3
 #define Align16		.p2align 4
