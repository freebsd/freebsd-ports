--- libtcc.c.orig	2009-05-18 16:27:06.000000000 +0200
+++ libtcc.c	2009-07-03 07:51:05.000000000 +0200
@@ -1509,10 +1509,18 @@
 
     if (level == 0) {
         /* XXX: only support linux */
+#if defined(__FreeBSD__) 
+        *paddr = uc->uc_mcontext.mc_rip;
+#else
         *paddr = uc->uc_mcontext.gregs[REG_RIP];
+#endif
         return 0;
     } else {
+#if defined(__FreeBSD__) 
+        fp = uc->uc_mcontext.mc_rbp;
+#else
         fp = uc->uc_mcontext.gregs[REG_RBP];
+#endif
         for(i=1;i<level;i++) {
             /* XXX: check address validity with program info */
             if (fp <= 0x1000)
