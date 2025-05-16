FreeBSD defines ElfW(x) to translate Linux's convention to FreeBSD's convention.
GCC defines ElfW to convert its convention to FreeBSD's convention. This patch
removes the conversion defined by GCC so that the FreeBSD conversion only is
applied.

--- libgcc/unwind-dw2-fde-dip.c.orig	2025-05-16 15:47:38 UTC
+++ libgcc/unwind-dw2-fde-dip.c
@@ -59,13 +59,13 @@
 
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
     && defined(TARGET_DL_ITERATE_PHDR) \
-    && defined(__linux__)
+    && (defined(__linux__) || defined(__FreeBSD__))
 # define USE_PT_GNU_EH_FRAME
 #endif
 
 #if !defined(inhibit_libc) && defined(HAVE_LD_EH_FRAME_HDR) \
     && defined(TARGET_DL_ITERATE_PHDR) \
-    && (defined(__DragonFly__) || defined(__FreeBSD__))
+    && defined(__DragonFly__)
 # define ElfW __ElfN
 # define USE_PT_GNU_EH_FRAME
 #endif
