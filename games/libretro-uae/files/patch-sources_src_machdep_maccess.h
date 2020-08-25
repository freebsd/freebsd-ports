--- sources/src/machdep/maccess.h.orig	2020-08-25 11:25:48 UTC
+++ sources/src/machdep/maccess.h
@@ -6,7 +6,7 @@
   * Copyright 1996 Bernd Schmidt
   */
 
-#if defined(__CELLOS_LV2__) || defined(WIIU)
+#if defined(__CELLOS_LV2__) || defined(WIIU) || defined(__powerpc__)
 
 STATIC_INLINE uae_u32 do_get_mem_long (uae_u32 *a)
 {
