--- lib/util/wordaccess.h.orig	Thu Jul 22 17:01:52 2004
+++ lib/util/wordaccess.h	Thu Aug 19 12:12:27 2004
@@ -47,7 +47,11 @@
   #if BITS_PER_WORD == 32
     typedef uint32n wordint;
   #else
+   #if BITS_PER_WORD == 64
+    typedef uint32n wordint;
+   #else
     #error "Don't know how to deal with this value of BITS_PER_WORD"
+   #endif
   #endif
 #else
   /* We can't do any fancy word-based stuff, but we can still fake it
