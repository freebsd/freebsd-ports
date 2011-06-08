--- ./elftoc/mknames.c.orig	2011-06-08 12:17:12.000000000 +0200
+++ ./elftoc/mknames.c	2011-06-08 12:20:02.000000000 +0200
@@ -108,17 +108,19 @@
     _("68K_", EM_68K),
     _("ALPHA_", EM_ALPHA),
     _("ARM_", EM_ARM),
-    _("CRIS_", EM_CRIS),
     __("HP_", "PARISC_", EM_PARISC),
     __("IA_64_", "IA64_", EM_IA_64),
-    _("M32R_", EM_M32R),
     _("MIPS_", EM_MIPS),
-    _("MN10300_", EM_MN10300),
     _("PPC_", EM_PPC),
     _("PPC64_", EM_PPC64),
     _("SH_", EM_SH),
     _("SPARC_", EM_SPARC),
     _("X86_64_", EM_X86_64),
+#if __FreeBSD_cc_version_ > 700022
+    _("CRIS_", EM_CRIS),
+    _("M32R_", EM_M32R),
+    _("MN10300_", EM_MN10300)
+#endif
 };
 
 #define machineidcount ((int)(sizeof machineids / sizeof *machineids))
