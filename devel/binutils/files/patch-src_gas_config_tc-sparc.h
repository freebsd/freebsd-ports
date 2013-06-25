===================================================================
RCS file: gas/config/tc-sparc.h,v
retrieving revision 1.31
retrieving revision 1.32
diff -u -r1.31 -r1.32
--- gas/config/tc-sparc.h	2010/10/22 12:08:29	1.31
+++ gas/config/tc-sparc.h	2013/03/26 13:49:12	1.32
@@ -33,7 +33,7 @@
 #define TARGET_ARCH bfd_arch_sparc
 
 #ifdef TE_FreeBSD
-#define ELF_TARGET_FORMAT	"elf32-sparc-freebsd"
+#define ELF_TARGET_FORMAT	"elf32-sparc"
 #define ELF64_TARGET_FORMAT	"elf64-sparc-freebsd"
 #endif
 
