--- src/arch/i386/x86_cpu_caps_detect_prk.nasm.orig	2005-12-17 12:50:39 UTC
+++ src/arch/i386/x86_cpu_caps_detect_prk.nasm
@@ -23,6 +23,7 @@
 ; using infos from sandpile.org
 
 ; returns 0 if no CPUID available
+[Section .text]
 global __alDetectx86CPUCaps
 global _alDetectx86CPUCaps
 
