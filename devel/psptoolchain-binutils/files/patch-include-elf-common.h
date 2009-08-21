--- include/elf/common.h.orig	2004-10-08 14:55:08.000000000 +0100
+++ include/elf/common.h	2006-05-09 02:55:36.000000000 +0100
@@ -93,6 +93,7 @@
 #define ET_HIOS		0xFEFF	/* Operating system-specific */
 #define ET_LOPROC	0xFF00	/* Processor-specific */
 #define ET_HIPROC	0xFFFF	/* Processor-specific */
+#define ET_PSPEXEC	0xFFA0	/* Sony PSP executable file */
 
 /* Values for e_machine, which identifies the architecture.  These numbers
    are officially assigned by registry@caldera.com.  See below for a list of
