--- include/iprt/x86.h.orig	2014-02-25 11:59:50.000000000 -0500
+++ include/iprt/x86.h	2014-03-11 16:46:08.000000000 -0400
@@ -35,6 +35,15 @@
 # pragma D depends_on library vbox-types.d
 #endif
 
+/* Workaround for FreeBSD machine/specialreg.h defining MSRs */
+#ifdef RT_OS_FREEBSD
+# undef MSR_P5_MC_ADDR
+# undef MSR_P5_MC_TYPE
+# undef MSR_IA32_PLATFORM_ID
+# undef MSR_BBL_CR_CTL3
+# undef MSR_IA32_MISC_ENABLE
+#endif
+
 /* Workaround for Solaris sys/regset.h defining CS, DS */
 #ifdef RT_OS_SOLARIS
 # undef CS
