--- src/dictionary.c.orig	2011-07-01 17:03:46.000000000 +0800
+++ src/dictionary.c	2011-07-01 17:04:55.000000000 +0800
@@ -39,6 +39,10 @@
   							Private functions
  ---------------------------------------------------------------------------*/
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 /* Doubles the allocated size associated to a pointer */
 /* 'size' is the current allocated size. */
 static void * mem_double(void * ptr, int size)
@@ -401,5 +405,10 @@
 	dictionary_del(d);
 	return 0 ;
 }
+
+#ifdef __cplusplus
+}
+#endif
+
 #endif
 /* vim: set ts=4 et sw=4 tw=75 */
