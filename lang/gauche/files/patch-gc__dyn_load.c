--- ./gc/dyn_load.c.orig	Sat Mar  4 12:55:43 2006
+++ ./gc/dyn_load.c	Tue May  9 14:38:56 2006
@@ -102,6 +102,12 @@
 #      else
 #        define ElfW(type) Elf64_##type
 #      endif
+#    elif defined(__FreeBSD__)
+#      if __ELF_WORD_SIZE == 32
+#        define ElfW(type) Elf32_##type
+#      else
+#        define ElfW(type) Elf64_##type
+#      endif
 #    else
 #      ifdef NETBSD
 #        if ELFSIZE == 32
