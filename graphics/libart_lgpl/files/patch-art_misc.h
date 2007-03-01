--- art_misc.h	2005/10/06 02:19:12	267
+++ art_misc.h	2007/03/01 16:18:41	278
@@ -34,9 +34,15 @@
 #include <libart_lgpl/art_config.h>
 #endif
 
+#ifdef __cplusplus
+extern "C" {
+#endif
 void *art_alloc(size_t size);
 void art_free(void *ptr);
 void *art_realloc(void *ptr, size_t size);
+#ifdef __cplusplus
+}
+#endif /* __cplusplus */
 
 /* These aren't, strictly speaking, configuration macros, but they're
    damn handy to have around, and may be worth playing with for
