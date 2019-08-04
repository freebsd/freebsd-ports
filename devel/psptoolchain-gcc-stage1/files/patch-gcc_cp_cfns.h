--- gcc/cp/cfns.h.orig	2019-07-29 17:16:40.469655000 +0200
+++ gcc/cp/cfns.h
@@ -53,6 +53,9 @@
 static unsigned int hash (const char *, unsigned int);
 #ifdef __GNUC__
 __inline
+#ifdef __GNUC_STDC_INLINE__
+__attribute__ ((__gnu_inline__))
+#endif
 #endif
 const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
