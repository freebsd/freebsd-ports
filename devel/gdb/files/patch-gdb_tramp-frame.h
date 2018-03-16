--- gdb/tramp-frame.h.orig	2018-03-15 10:38:21.385046000 +0100
+++ gdb/tramp-frame.h	2018-03-15 10:38:49.942224000 +0100
@@ -41,7 +41,7 @@
 
 /* Magic instruction that to mark the end of the signal trampoline
    instruction sequence.  */
-#define TRAMP_SENTINEL_INSN ((LONGEST) -1)
+#define TRAMP_SENTINEL_INSN ((ULONGEST) -1)
 
 struct tramp_frame
 {
