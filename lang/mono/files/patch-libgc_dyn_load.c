--- libgc/dyn_load.c.orig	Tue May 18 14:42:19 2004
+++ libgc/dyn_load.c	Sat Jun 12 15:23:33 2004
@@ -91,6 +91,13 @@
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
 #    ifdef __NetBSD__
 #      if ELFSIZE == 32
 #        define ElfW(type) Elf32_##type
@@ -104,6 +111,7 @@
 #        define ElfW(type) Elf64_##type
 #      endif
 #    endif
+#endif
 #  endif
 
 #if defined(SUNOS5DL) && !defined(USE_PROC_FOR_LIBRARIES)
