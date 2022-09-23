--- util.c.orig	2022-04-12 11:48:55 UTC
+++ util.c
@@ -214,6 +214,7 @@ typedef int (cmpfunc_t)(const void*, const void*, void
 
 typedef int (cmpfunc_t)(const void*, const void*, void*);
 
+#if !defined HAVE_GNU_QSORT_R
 #if defined HAVE_QSORT_S && defined RUBY_MSVCRT_VERSION
 /* In contrast to its name, Visual Studio qsort_s is incompatible with
  * C11 in the order of the comparison function's arguments, and same
@@ -259,7 +260,7 @@ ruby_qsort(void* base, const size_t nel, const size_t 
     qsort_s(base, nel, size, cmp, d);
 }
 # define HAVE_GNU_QSORT_R 1
-#elif !defined HAVE_GNU_QSORT_R
+#else
 /* mm.c */
 
 #define mmtype long
@@ -525,7 +526,8 @@ ruby_qsort(void* base, const size_t nel, const size_t 
     else goto nxt;                         /* need not to sort both sides */
   }
 }
-#endif /* HAVE_GNU_QSORT_R */
+#endif
+#endif /* !HAVE_GNU_QSORT_R */
 
 char *
 ruby_strdup(const char *str)
