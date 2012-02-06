--- ./include/elf/common.h.orig	2011-07-22 20:22:36.000000000 +0000
+++ ./include/elf/common.h	2012-01-21 13:31:35.000000000 +0000
@@ -96,6 +96,7 @@
 #define ET_HIOS		0xFEFF	/* Operating system-specific */
 #define ET_LOPROC	0xFF00	/* Processor-specific */
 #define ET_HIPROC	0xFFFF	/* Processor-specific */
+#define ET_PSPEXEC  0xFFA0  /* Sony PSP executable file */
 
 /* Values for e_machine, which identifies the architecture.  These numbers
    are officially assigned by registry@sco.com.  See below for a list of
