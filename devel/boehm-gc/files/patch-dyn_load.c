--- dyn_load.c.orig	2004-05-05 11:53:09.000000000 +0200
+++ dyn_load.c	2004-05-05 12:03:40.000000000 +0200
@@ -91,11 +91,19 @@
 /* Newer versions of GNU/Linux define this macro.  We
  * define it similarly for any ELF systems that don't.  */
 #  ifndef ElfW
+#ifdef __FreeBSD__
+#if __ELF_WORD_SIZE == 32
+#define ElfW(type) Elf32_##type
+#else
+#define ElfW(type) Elf64_##type
+#endif
+#else
 #    if !defined(ELF_CLASS) || ELF_CLASS == ELFCLASS32
 #      define ElfW(type) Elf32_##type
 #    else
 #      define ElfW(type) Elf64_##type
 #    endif
+#endif
 #  endif
 
 #if defined(SUNOS5DL) && !defined(USE_PROC_FOR_LIBRARIES)
