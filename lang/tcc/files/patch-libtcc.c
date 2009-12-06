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
     tcc_define_symbol(s, "__i386__", NULL);
+    tcc_define_symbol(s, "__i386", NULL); /* NULL defaults to "1" */
+    tcc_define_symbol(s, "i386", NULL);
 #endif
 #if defined(TCC_TARGET_X86_64)
     tcc_define_symbol(s, "__x86_64__", NULL);
@@ -1802,6 +1812,14 @@
 #else
     tcc_define_symbol(s, "__unix__", NULL);
     tcc_define_symbol(s, "__unix", NULL);
+    tcc_define_symbol(s, "unix", NULL);
+#if defined(__FreeBSD__)
+#define str(s) #s
+    tcc_define_symbol(s, "__FreeBSD__", str( __FreeBSD__));
+#undef str
+    tcc_define_symbol(s, "__aligned(x)", "__attribute__((__aligned__(x)))");
+    tcc_define_symbol(s, "__packed", "__attribute__((packed))");
+#endif
 #if defined(__linux)
     tcc_define_symbol(s, "__linux__", NULL);
     tcc_define_symbol(s, "__linux", NULL);
@@ -1834,6 +1841,9 @@
     tcc_define_symbol(s, "__TINYC__", NULL);

     /* tiny C & gcc defines */
+    tcc_define_symbol(s, "__CC_SUPPORTS___INLINE", NULL);
+    tcc_define_symbol(s, "__builtin_inline(x,y)", "(x)");
+    tcc_define_symbol(s, "__PRETTY_FUNCTION__", "__FUNCTION__");
     tcc_define_symbol(s, "__SIZE_TYPE__", "unsigned int");
     tcc_define_symbol(s, "__PTRDIFF_TYPE__", "int");
 #ifdef TCC_TARGET_PE
