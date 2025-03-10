--- include/iprt/x86.h.orig	2021-04-20 04:22:23 UTC
+++ include/iprt/x86.h
@@ -38,6 +38,16 @@
 # pragma D depends_on library vbox-types.d
 #endif
 
+/* Workaround for FreeBSD machine/specialreg.h defining MSRs */
+#ifdef RT_OS_FREEBSD
+# undef MSR_P5_MC_ADDR
+# undef MSR_P5_MC_TYPE
+# undef MSR_IA32_PLATFORM_ID
+# undef MSR_BBL_CR_CTL3
+# undef MSR_IA32_MISC_ENABLE
+# undef MSR_IA32_FEATURE_CONTROL
+#endif
+
 /** Workaround for Solaris sys/regset.h defining CS, DS and sys/controlregs.h
  * defining MSR_IA32_FLUSH_CMD */
 #ifdef RT_OS_SOLARIS
