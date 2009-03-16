--- src/arch/i386/memcpy_mmx_prk.nasm.orig	2005-12-17 15:50:39.000000000 +0300
+++ src/arch/i386/memcpy_mmx_prk.nasm	2009-03-16 17:20:23.000000000 +0300
@@ -22,6 +22,7 @@
 ; pretty straight-forward implementation
 ; by design broken for n<8, so check that before calling
 ; x86 32 bit only!
+[Section .text]
 global __alMMXmemcpy
 global _alMMXmemcpy
 
