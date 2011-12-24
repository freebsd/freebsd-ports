--- ./gas/config/tc-ppc.c.orig	2011-06-14 11:03:51.000000000 +0200
+++ ./gas/config/tc-ppc.c	2011-12-21 09:44:40.000000000 +0100
@@ -1370,7 +1370,9 @@
 #endif
 #endif
 #ifdef OBJ_ELF
-# ifdef TE_VXWORKS
+# ifdef TE_FreeBSD
+  return (ppc_obj64 ? "elf64-powerpc-freebsd" : "elf32-powerpc-freebsd");
+# elif defined (TE_VXWORKS)
   return "elf32-powerpc-vxworks";
 # else
   return (target_big_endian
