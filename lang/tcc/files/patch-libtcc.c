diff -ubwr ./libtcc.c ../../work.2/tcc-0.9.25/libtcc.c
--- ./libtcc.c	2009-05-18 16:27:06.000000000 +0200
+++ ../../work.2/tcc-0.9.25/libtcc.c	2009-11-29 02:25:14.000000000 +0100
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
@@ -1784,7 +1792,9 @@
     tcc_define_symbol(s, "__STDC__", NULL);
     tcc_define_symbol(s, "__STDC_VERSION__", "199901L");
 #if defined(TCC_TARGET_I386)
-    tcc_define_symbol(s, "__i386__", NULL);
+    tcc_define_symbol(s, "__i386__", "1");
+    tcc_define_symbol(s, "__i386", "1");
+    tcc_define_symbol(s, "i386", "1");
 #endif
 #if defined(TCC_TARGET_X86_64)
     tcc_define_symbol(s, "__x86_64__", NULL);
@@ -1802,8 +1812,15 @@
 #ifdef TCC_TARGET_PE
     tcc_define_symbol(s, "_WIN32", NULL);
 #else
-    tcc_define_symbol(s, "__unix__", NULL);
-    tcc_define_symbol(s, "__unix", NULL);
+    tcc_define_symbol(s, "__unix__", "1");
+    tcc_define_symbol(s, "__unix", "1");
+    tcc_define_symbol(s, "unix", "1");
+#if defined(__FreeBSD__)
+#define str(s) #s
+    tcc_define_symbol(s, "__FreeBSD__", str( __FreeBSD__));
+    tcc_define_symbol(s, "__INTEL_COMPILER", "1");
+#undef str
+#endif
 #if defined(__linux)
     tcc_define_symbol(s, "__linux__", NULL);
     tcc_define_symbol(s, "__linux", NULL);
