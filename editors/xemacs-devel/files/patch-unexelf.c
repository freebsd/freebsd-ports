--- src/unexelf.c.orig	Fri Jul 22 23:34:12 2005
+++ src/unexelf.c	Fri Jul 22 23:34:42 2005
@@ -477,7 +477,7 @@
 # include <sys/exec_elf.h>
 #endif
 
-#if defined(__FreeBSD__) && (defined(__alpha__) || defined(__amd64__)) 
+#if defined(__FreeBSD__) && (defined(__alpha__) || defined(_LP64)) 
 # ifdef __STDC__ 
 #  define ElfW(type)   Elf64_##type 
 # else 
