diff -ruN petit.orig/engine/common.h petit/engine/common.h
--- engine/common.h.orig	Sat Mar 16 16:19:29 2002
+++ engine/common.h	Thu Nov  6 13:18:32 2003
@@ -18,7 +18,7 @@
 #endif
 
 /* ‘S‘Rˆê”Ê“I‚Å‚È‚¢ */
-#if defined(WIN32) || defined(__linux__) || defined(DOS) || defined(_M_IX86) || defined(__os2__) || defined(_X86_)
+#if defined(WIN32) || defined(__linux__) || defined(DOS) || defined(_M_IX86) || defined(__os2__) || defined(_X86_) || defined(__FreeBSD__)
 	#define CPU_I386
 	#define MIE_LITTLE_ENDIAN
 #elif define(__MWERKS__)
