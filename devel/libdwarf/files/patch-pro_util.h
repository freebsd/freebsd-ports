--- pro_util.h.orig	2011-06-18 08:46:00.000000000 +0200
+++ pro_util.h	2011-06-18 14:45:59.000000000 +0200
@@ -34,6 +34,9 @@
 
 */
 
+#if defined(__FreeBSD__)
+# include <osreldate.h>
+#endif
 
 
 
@@ -120,7 +123,9 @@
 #define Get_REL_SEGREL_isa(dbg)    (R_386_NONE) /* I don't know! */
 #endif /* sparc || i386 */
 #else  /* !sun */
-#ifdef HAVE_SYS_IA64_ELF_H
+#if defined(HAVE_SYS_IA64_ELF_H) ||\
+   /* FreeBSD 7.x and above always have these */ \
+   (defined(__FreeBSD__) && __FreeBSD_version > 700000)
 #define Get_REL64_isa(dbg)         (ISA_IA64(dbg) ? \
     DWARF_PRO_R_IA64_DIR64LSB : R_MIPS_64)
 #define Get_REL32_isa(dbg)         (ISA_IA64(dbg) ? \
