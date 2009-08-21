--- include/elf/common.h.orig	2005-09-30 16:12:52.000000000 +0100
+++ include/elf/common.h	2007-02-08 20:06:04.000000000 +0000
@@ -93,6 +93,7 @@
 #define ET_HIOS		0xFEFF	/* Operating system-specific */
 #define ET_LOPROC	0xFF00	/* Processor-specific */
 #define ET_HIPROC	0xFFFF	/* Processor-specific */
+#define ET_PSPEXEC	0xFFA0	/* Sony PSP executable file */
 
 /* Values for e_machine, which identifies the architecture.  These numbers
    are officially assigned by registry@caldera.com.  See below for a list of
