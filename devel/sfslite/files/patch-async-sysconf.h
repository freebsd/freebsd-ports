--- async/sysconf.h.orig	Thu Aug 30 16:57:16 2007
+++ async/sysconf.h	Fri Sep 14 01:46:21 2007
@@ -495,15 +495,16 @@
 #include <dmalloc.h>
 
 #undef memcpy
+#undef memmove
 #undef xfree
 
 #if DMALLOC_VERSION_MAJOR < 5  || \
      (DMALLOC_VERSION_MAJOR == 5 && DMALLOC_VERSION_MINOR < 5)
 
 #define memcpy(to, from, len) \
-  _dmalloc_memcpy((char *) (to), (const char *) (from), len)
+  _dmalloc_memcpy(__FILE__, __LINE__, (char *) (to), (const char *) (from), len)
 #define memmove(to, from, len) \
-  _dmalloc_bcopy((const char *) (from), (char *) (to), len)
+  _dmalloc_bcopy(__FILE__, __LINE__, (const char *) (from), (char *) (to), len)
 
 #endif /* version < 5.5 */
 
@@ -515,7 +516,7 @@
   dmalloc_malloc (f, l, s, DMALLOC_FUNC_MALLOC, 0, 0)
 #define _xfree_leap(f, l, p) dmalloc_free (f, l, p, DMALLOC_FUNC_FREE)
 #undef xstrdup 
-#define xstrdup(__s) ((char *) dmalloc_strdup(__FILE__, __LINE__, __s, 1))
+#define xstrdup(__s) ((char *) dmalloc_strndup(__FILE__, __LINE__, __s, -1, 1))
 #endif /* DMALLOC_VERSION_MAJOR >= 5 */
 
 static inline void
