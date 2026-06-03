--- lib/bpf/src/bpf.c.orig	2026-03-24 09:21:58 UTC
+++ lib/bpf/src/bpf.c
@@ -59,6 +59,8 @@
 #  define __NR_bpf 6319
 # elif defined(__mips__) && defined(_ABI64)
 #  define __NR_bpf 5315
+# elif defined(__powerpc__)
+#  define __NR_bpf 361
 # else
 #  error __NR_bpf not defined. libbpf does not support your arch.
 # endif
