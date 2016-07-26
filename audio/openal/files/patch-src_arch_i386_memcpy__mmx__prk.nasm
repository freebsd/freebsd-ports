--- src/arch/i386/memcpy_mmx_prk.nasm.orig	2005-12-17 12:50:39 UTC
+++ src/arch/i386/memcpy_mmx_prk.nasm
@@ -22,6 +22,7 @@
 ; pretty straight-forward implementation
 ; by design broken for n<8, so check that before calling
 ; x86 32 bit only!
+[Section .text]
 global __alMMXmemcpy
 global _alMMXmemcpy
 
