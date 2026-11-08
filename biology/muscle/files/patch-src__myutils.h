--- myutils.h.orig	2026-08-29 19:37:51 UTC
+++ myutils.h
@@ -11,7 +11,7 @@
 #define TRACK_ALLOC		0
 #define ALLOC_TOTALS	0
 
-#if defined(__x86_64__) || defined(_M_X64) || defined(__arm64__)
+#if defined(__x86_64__) || defined(_M_X64) || defined(__arm64__) || defined(__LP64__)
 #define	BITS			64
 #else
 #define	BITS			32
