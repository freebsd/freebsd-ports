--- conf.h.orig	Wed Jan 28 02:49:57 2004
+++ conf.h	Tue Feb 17 06:24:41 2004
@@ -109,7 +109,7 @@
 #    define UPX_E_OK      UCL_E_OK
 #    define UPX_E_ERROR   UCL_E_ERROR
 #    define UPX_E_OUT_OF_MEMORY UCL_E_OUT_OF_MEMORY
-#    define __UPX_ENTRY   __UCL_ENTRY
+#    define __UPX_ENTRY
 #  endif
 #endif
 #if defined(WITH_NRV)
@@ -518,6 +518,7 @@
 #define UPX_F_BVMLINUZ_i386     16
 #define UPX_F_ELKS_8086         17
 #define UPX_F_PS1_EXE           18
+#define UPX_F_FREEBSD_i386      19
 #define UPX_F_ATARI_TOS         129
 #define UPX_F_SOLARIS_SPARC     130
 
