--- dbg_mlc.c.orig	Tue May 13 16:59:49 2003
+++ dbg_mlc.c	Wed May 12 20:13:19 2004
@@ -414,6 +414,23 @@
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
 # ifdef __STDC__
     GC_PTR GC_debug_malloc(size_t lb, GC_EXTRA_PARAMS)
 # else
@@ -428,6 +445,13 @@
 {
     GC_PTR result = GC_malloc(lb + DEBUG_BYTES);
     
+#ifdef GC_ADD_CALLER
+    if (s == NULL) {
+      GC_caller_func_offset(ra, &s, &i);
+      if (s == NULL)
+        s = "unknown";
+    }
+#endif
     if (result == 0) {
         GC_err_printf1("GC_debug_malloc(%ld) returning NIL (",
         	       (unsigned long) lb);
@@ -789,6 +813,13 @@
     register size_t old_sz;
     register hdr * hhdr;
     
+#ifdef GC_ADD_CALLER
+    if (s == NULL) {
+      GC_caller_func_offset(ra, &s, &i);
+      if (s == NULL)
+        s = "unknown";
+    }
+#endif
     if (p == 0) return(GC_debug_malloc(lb, OPT_RA s, i));
     if (base == 0) {
         GC_err_printf1(
@@ -1094,7 +1125,11 @@
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
@@ -1102,12 +1137,12 @@
 GC_PTR GC_debug_malloc_replacement(lb)
 size_t lb;
 {
-    return GC_debug_malloc(lb, RA "unknown", 0);
+    return GC_debug_malloc(lb, RA NULL, 0);
 }
 
 GC_PTR GC_debug_realloc_replacement(p, lb)
 GC_PTR p;
 size_t lb;
 {
-    return GC_debug_realloc(p, lb, RA "unknown", 0);
+    return GC_debug_realloc(p, lb, RA NULL, 0);
 }
