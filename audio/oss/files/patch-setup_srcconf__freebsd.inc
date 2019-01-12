--- setup/srcconf_freebsd.inc.orig	2014-02-14 22:59:55 UTC
+++ setup/srcconf_freebsd.inc
@@ -10,8 +10,10 @@ check_sysdep (conf_t * conf, struct utsname *un)
 static void
 add_kernel_flags (FILE * f)
 {
+  fprintf (f, "CFLAGS += -DKLD_MODULE ");
 # if defined(__x86_64__)
   fprintf (f,
-	     "CFLAGS += -O3 -fno-common  -mcmodel=kernel -mno-red-zone  -fno-asynchronous-unwind-tables -ffreestanding\n");
+	     "-O3 -fno-common -mcmodel=kernel -mno-red-zone  -fno-asynchronous-unwind-tables -ffreestanding -mno-sse");
 # endif
+  fprintf(f, "\n");
 }
