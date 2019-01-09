--- setup/srcconf_freebsd.inc.orig	2014-02-14 22:59:55 UTC
+++ setup/srcconf_freebsd.inc
@@ -12,6 +12,6 @@ add_kernel_flags (FILE * f)
 {
 # if defined(__x86_64__)
   fprintf (f,
-	     "CFLAGS += -O3 -fno-common  -mcmodel=kernel -mno-red-zone  -fno-asynchronous-unwind-tables -ffreestanding\n");
+	     "CFLAGS += -O3 -fno-common  -DKLD_MODULE -mcmodel=kernel -mno-red-zone  -fno-asynchronous-unwind-tables -ffreestanding -mno-sse\n");
 # endif
 }
