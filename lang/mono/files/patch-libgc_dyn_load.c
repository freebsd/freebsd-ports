--- libgc/dyn_load.c.orig	Sat Jul 17 11:31:47 2004
+++ libgc/dyn_load.c	Sun Sep 12 04:09:10 2004
@@ -96,6 +96,13 @@
 /* Newer versions of GNU/Linux define this macro.  We
  * define it similarly for any ELF systems that don't.  */
 #  ifndef ElfW
+#ifdef FREEBSD
+#if __ELF_WORD_SIZE == 32
+#define ElfW(type) Elf32_##type
+#else
+#define ElfW(type) Elf64_##type
+#endif
+#else
 #    ifdef NETBSD
 #      if ELFSIZE == 32
 #        define ElfW(type) Elf32_##type
@@ -110,6 +117,7 @@
 #      endif
 #    endif
 #  endif
+#endif
 
 #if defined(SUNOS5DL) && !defined(USE_PROC_FOR_LIBRARIES)
 
