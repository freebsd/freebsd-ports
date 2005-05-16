--- libgc/dbg_mlc.c.orig	Sat Nov 13 13:52:28 2004
+++ libgc/dbg_mlc.c	Thu May  5 17:34:31 2005
@@ -475,6 +475,23 @@
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
@@ -489,6 +506,13 @@
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
@@ -858,6 +882,13 @@
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
@@ -1166,7 +1197,11 @@
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
@@ -1174,12 +1209,12 @@
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
