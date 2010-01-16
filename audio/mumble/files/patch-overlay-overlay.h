diff -r -C 2 mumble-1.1.8/overlay/overlay.h overlay/overlay.h
*** mumble-1.1.8/overlay/overlay.h	2009-03-22 16:05:00.000000000 +0100
--- overlay/overlay.h	2009-08-06 20:07:48.000000000 +0200
***************
*** 43,46 ****
--- 43,65 ----
  #define OVERLAY_VERSION_SUB 0
  
+ /* BSD support */
+ #ifndef ElfW
+ # ifdef __FreeBSD__
+ #  if __ELF_WORD_SIZE == 32
+ #   define ElfW(type) Elf32_##type
+ #  else
+ #   define ElfW(type) Elf64_##type
+ #  endif
+ # else
+ # ifdef __NetBSD__
+ #  if ELFSIZE == 32
+ #   define ElfW(type) Elf32_##type
+ #  else 
+ #   define ElfW(type) Elf64_##type
+ #  endif
+ # endif
+ # endif
+ #endif
+ 
  struct TextEntry {
  	unsigned int color;
