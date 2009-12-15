--- dbg_mlc.c.orig	2009-10-20 00:34:39.000000000 +0400
+++ dbg_mlc.c	2009-10-20 00:41:22.000000000 +0400
@@ -456,10 +456,34 @@
     GC_register_displacement((word)sizeof(oh) + offset);
 }
 
+#if defined(__FreeBSD__)
+#include <dlfcn.h>
+static void GC_caller_func_offset(ad, symp, offp)
+const GC_word ad;
+const char **symp;
+int *offp;
+{
+    Dl_info caller;
+    if (dladdr((const void *)ad, &caller) && caller.dli_sname != NULL) {
+      *symp = caller.dli_sname;
+      *offp = (const char *)ad - (const char *)caller.dli_saddr;
+    }
+}
+#else
+#define GC_caller_func(ad, symp, offp)
+#endif
+
 void * GC_debug_malloc(size_t lb, GC_EXTRA_PARAMS)
 {
     void * result = GC_malloc(lb + DEBUG_BYTES);
-    
+
+#ifdef GC_ADD_CALLER
+    if (s == NULL) {
+      GC_caller_func_offset(ra, &s, &i);
+      if (s == NULL)
+        s = "unknown";
+    }
+#endif
     if (result == 0) {
         GC_err_printf("GC_debug_malloc(%lu) returning NIL (",
         	      (unsigned long) lb);
@@ -764,6 +788,13 @@
     size_t old_sz;
     hdr * hhdr;
     
+#ifdef GC_ADD_CALLER
+    if (s == NULL) {
+      GC_caller_func_offset(ra, &s, &i);
+      if (s == NULL)
+        s = "unknown";
+    }
+#endif
     if (p == 0) return(GC_debug_malloc(lb, OPT_RA s, i));
     if (base == 0) {
         GC_err_printf("Attempt to reallocate invalid pointer %p\n", p);
@@ -1041,17 +1072,21 @@
 }
 
 #ifdef GC_ADD_CALLER
-# define RA GC_RETURN_ADDR,
+# ifdef GC_RETURN_ADDR_PARENT
+#  define RA GC_RETURN_ADDR_PARENT,
+# else
+#  define RA GC_RETURN_ADDR,
+# endif
 #else
 # define RA
 #endif
 
 void * GC_debug_malloc_replacement(size_t lb)
 {
-    return GC_debug_malloc(lb, RA "unknown", 0);
+    return GC_debug_malloc(lb, RA NULL, 0);
 }
 
 void * GC_debug_realloc_replacement(void *p, size_t lb)
 {
-    return GC_debug_realloc(p, lb, RA "unknown", 0);
+    return GC_debug_realloc(p, lb, RA NULL, 0);
 }
