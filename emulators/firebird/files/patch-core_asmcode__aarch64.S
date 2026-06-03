--- core/asmcode_aarch64.S.orig	2022-12-31 20:54:26 UTC
+++ core/asmcode_aarch64.S
@@ -1,5 +1,5 @@
 .macro loadsym reg, name
-	#if defined(__clang__) && !defined(ANDROID)
+	#if defined(__clang__) && !defined(ANDROID) && !defined(__FreeBSD__)
 		adrp \reg, \name\()@PAGE
 		add \reg, \reg, \name\()@PAGEOFF
 	#else
