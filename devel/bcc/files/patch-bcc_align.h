--- bcc/align.h.orig	1992-11-14 15:12:33 UTC
+++ bcc/align.h
@@ -6,7 +6,7 @@
 # define align(x) (x)
 #else
 # ifdef UNPORTABLE_ALIGNMENT
-typedef unsigned pointerint_t;
+typedef unsigned long pointerint_t;
 #  define align(x) (((pointerint_t) (x) + (S_ALIGNMENT-1)) & ~(S_ALIGNMENT-1))
 # else
 #  define align(x) ((char *) (x) + (- (int) (x) & (S_ALIGNMENT-1)))
