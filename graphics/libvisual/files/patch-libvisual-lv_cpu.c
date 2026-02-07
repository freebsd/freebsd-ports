--- libvisual/lv_cpu.c.orig	2010-04-25 17:13:26.000000000 +0200
+++ libvisual/lv_cpu.c	2010-04-25 17:11:29.000000000 +0200
@@ -423,7 +423,7 @@
 #endif
 #endif /* VISUAL_ARCH_X86 */
 
-#if VISUAL_ARCH_POWERPC
+#if defined(VISUAL_ARCH_POWERPC)
 	check_os_altivec_support ();
 #endif /* VISUAL_ARCH_POWERPC */
