--- arch/lkl/include/uapi/asm/host_ops.h.orig	2018-06-28 05:58:16 UTC
+++ arch/lkl/include/uapi/asm/host_ops.h
@@ -7,7 +7,7 @@ struct lkl_jmp_buf {
 struct lkl_tls_key;
 typedef unsigned long lkl_thread_t;
 struct lkl_jmp_buf {
-	unsigned long buf[32];
+	unsigned long buf[128];
 };
 
 /**
