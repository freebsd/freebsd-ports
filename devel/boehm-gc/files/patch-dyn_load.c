--- dyn_load.c.orig	Thu May  6 08:03:06 2004
+++ dyn_load.c	Sun Oct 31 01:53:01 2004
@@ -97,6 +97,12 @@
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
 #      if !defined(ELF_CLASS) || ELF_CLASS == ELFCLASS32
 #        define ElfW(type) Elf32_##type
