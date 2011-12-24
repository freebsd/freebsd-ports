--- ./bfd/targets.c.orig	2011-08-17 02:39:38.000000000 +0200
+++ ./bfd/targets.c	2011-12-21 09:44:40.000000000 +0100
@@ -667,6 +667,7 @@
 extern const bfd_target bfd_elf32_pjl_vec;
 extern const bfd_target bfd_elf32_powerpc_vec;
 extern const bfd_target bfd_elf32_powerpcle_vec;
+extern const bfd_target bfd_elf32_powerpc_freebsd_vec;
 extern const bfd_target bfd_elf32_powerpc_vxworks_vec;
 extern const bfd_target bfd_elf32_rx_le_vec;
 extern const bfd_target bfd_elf32_rx_be_vec;
@@ -729,6 +730,7 @@
 extern const bfd_target bfd_elf64_mmix_vec;
 extern const bfd_target bfd_elf64_powerpc_vec;
 extern const bfd_target bfd_elf64_powerpcle_vec;
+extern const bfd_target bfd_elf64_powerpc_freebsd_vec;
 extern const bfd_target bfd_elf64_s390_vec;
 extern const bfd_target bfd_elf64_sh64_vec;
 extern const bfd_target bfd_elf64_sh64l_vec;
@@ -1033,6 +1035,7 @@
 	&bfd_elf32_powerpc_vec,
 	&bfd_elf32_powerpc_vxworks_vec,
 	&bfd_elf32_powerpcle_vec,
+	&bfd_elf32_powerpc_freebsd_vec,
 	&bfd_elf32_rx_be_vec,
 	&bfd_elf32_rx_be_ns_vec,
 	&bfd_elf32_rx_le_vec,
@@ -1095,6 +1098,7 @@
 	&bfd_elf64_mmix_vec,
 	&bfd_elf64_powerpc_vec,
 	&bfd_elf64_powerpcle_vec,
+	&bfd_elf64_powerpc_freebsd_vec,
 	&bfd_elf64_s390_vec,
 	&bfd_elf64_sh64_vec,
 	&bfd_elf64_sh64l_vec,
