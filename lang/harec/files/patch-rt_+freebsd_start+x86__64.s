--- rt/+freebsd/start+x86_64.s.orig	2022-04-28 14:14:40 UTC
+++ rt/+freebsd/start+x86_64.s
@@ -2,5 +2,6 @@ _start:
 .global _start
 _start:
 	xor %rbp, %rbp
+	pushq %rbp
 	movq %rsp, %rdi
 	call rt.start_ha
