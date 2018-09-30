--- src/core/uae/sysdeps.h.orig	2007-06-24 05:05:05 UTC
+++ src/core/uae/sysdeps.h
@@ -138,7 +138,7 @@ extern void *xcalloc(size_t, size_t);
 #define ENUMNAME(name) name
 
 /* While we're here, make abort more useful.  */
-#define abort() \
+#define uae_abort() \
   do { \
     fprintf (stderr, "UAE: Internal error; file %s, line %d\n", __FILE__, __LINE__); \
     (abort) (); \
