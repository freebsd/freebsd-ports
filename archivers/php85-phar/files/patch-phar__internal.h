--- phar_internal.h.orig	2025-08-19 05:47:26 UTC
+++ phar_internal.h
@@ -17,6 +17,9 @@
   +----------------------------------------------------------------------+
 */
 
+#ifndef PHAR_PHAR_INTERNAL_H
+#define PHAR_PHAR_INTERNAL_H
+
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
@@ -487,3 +490,5 @@ END_EXTERN_C()
 phar_path_check_result phar_path_check(char **p, size_t *len, const char **error);
 
 END_EXTERN_C()
+
+#endif /* PHAR_PHAR_INTERNAL_H */
