--- async/sysconf.h	2005-11-01 18:20:33.000000000 +0200
+++ async/sysconf.h_new	2007-07-07 00:36:00.000000000 +0300
@@ -494,11 +494,12 @@
 #endif /* HAVE_MEMORY_H */
 #include <dmalloc.h>
 #undef memcpy
+#undef memmove
 #undef xfree
 #define memcpy(to, from, len) \
-  _dmalloc_memcpy((char *) (to), (const char *) (from), len)
+  _dmalloc_memcpy(__FILE__, __LINE__, (char *) (to), (const char *) (from), len)
 #define memmove(to, from, len) \
-  _dmalloc_bcopy((const char *) (from), (char *) (to), len)
+  _dmalloc_bcopy(__FILE__, __LINE__, (const char *) (from), (char *) (to), len)
 /* Work around Dmalloc's misunderstanding of free's definition */
 
 #if DMALLOC_VERSION_MAJOR >= 5
@@ -508,7 +509,7 @@
   dmalloc_malloc (f, l, s, DMALLOC_FUNC_MALLOC, 0, 0)
 #define _xfree_leap(f, l, p) dmalloc_free (f, l, p, DMALLOC_FUNC_FREE)
 #undef xstrdup 
-#define xstrdup(__s) ((char *) dmalloc_strdup(__FILE__, __LINE__, __s, 1))
+#define xstrdup(__s) ((char *) dmalloc_strndup(__FILE__, __LINE__, __s, -1, 1))
 #endif /* DMALLOC_VERSION_MAJOR >= 5 */
 
 static inline void
