--- lzf/lzf_filter.c.orig	2022-11-26 00:17:16 UTC
+++ lzf/lzf_filter.c
@@ -51,11 +51,7 @@
         macro H5_USE_16_API is set
 */
 
-#if H5_VERS_MAJOR == 1 && H5_VERS_MINOR == 8 && (H5_VERS_RELEASE < 3 || !H5_USE_16_API)
 #define H5PY_H5Z_NEWCLS 1
-#else
-#define H5PY_H5Z_NEWCLS 0   
-#endif
 
 size_t lzf_filter(unsigned flags, size_t cd_nelmts,
 		    const unsigned cd_values[], size_t nbytes,
