--- pro_util.h.orig	2011-06-18 08:45:01.000000000 +0200
+++ pro_util.h	2011-06-18 08:45:50.000000000 +0200
@@ -120,7 +120,7 @@
 #define Get_REL_SEGREL_isa(dbg)    (R_386_NONE) /* I don't know! */
 #endif /* sparc || i386 */
 #else  /* !sun */
-#ifdef HAVE_SYS_IA64_ELF_H
+#if defined(HAVE_SYS_IA64_ELF_H) || defined(__FreeBSD__)
 #define Get_REL64_isa(dbg)         (ISA_IA64(dbg) ? \
     DWARF_PRO_R_IA64_DIR64LSB : R_MIPS_64)
 #define Get_REL32_isa(dbg)         (ISA_IA64(dbg) ? \
