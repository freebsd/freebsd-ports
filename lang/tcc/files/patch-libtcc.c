--- libtcc.c.orig	2013-02-15 14:24:00 UTC
+++ libtcc.c
@@ -931,7 +931,11 @@ LIBTCCAPI TCCState *tcc_new(void)
     tcc_define_symbol(s, "__i386", NULL);
     tcc_define_symbol(s, "i386", NULL);
 #elif defined(TCC_TARGET_X86_64)
+# if defined(__FreeBSD__)
+    tcc_define_symbol(s, "__amd64__", NULL);
+# endif
     tcc_define_symbol(s, "__x86_64__", NULL);
+    tcc_define_symbol(s, "__LP64__", NULL);
 #elif defined(TCC_TARGET_ARM)
     tcc_define_symbol(s, "__ARM_ARCH_4__", NULL);
     tcc_define_symbol(s, "__arm_elf__", NULL);
@@ -957,6 +961,13 @@ LIBTCCAPI TCCState *tcc_new(void)
     tcc_define_symbol(s, "__linux", NULL);
 # endif
 # if defined(__FreeBSD__)
+#  if defined(DEFINE_VA_LIST)
+#   if defined(TCC_TARGET_X86_64)
+    tcc_define_symbol(s, "__va_list", "struct { long pad[3]; }");
+#   else
+    tcc_define_symbol(s, "__va_list", "char *");
+#   endif
+#  endif
 #  define str(s) #s
     tcc_define_symbol(s, "__FreeBSD__", str( __FreeBSD__));
 #  undef str
