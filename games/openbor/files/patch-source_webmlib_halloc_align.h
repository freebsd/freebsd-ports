GCC 5.0 defaults to -std=gnu11 which exposes max_align_t in its stddef.h.
Clang also provides max_align_t but not on FreeBSD (see bug 193594).

  In file included from source/webmlib/halloc/halloc.c:19:0:
  source/webmlib/halloc/align.h:42:25: error: conflicting types for 'max_align_t'
   typedef union max_align max_align_t;
                           ^
  In file included from source/webmlib/halloc/halloc.h:18:0,
                   from source/webmlib/halloc/halloc.c:18:
  /usr/local/lib/gcc5/**/include/stddef.h:429:3: note: previous declaration of 'max_align_t' was here
   } max_align_t;
     ^

--- source/webmlib/halloc/align.h.orig	2015-04-09 22:13:36 UTC
+++ source/webmlib/halloc/align.h
@@ -22,7 +22,7 @@
  */
 typedef double max_align_t;
 
-#else
+#elif !defined(__CLANG_MAX_ALIGN_T_DEFINED) && !defined(_GCC_MAX_ALIGN_T)
 
 /*
  *	a type with the most strict alignment requirements
