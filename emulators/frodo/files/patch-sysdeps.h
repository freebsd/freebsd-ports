--- sysdeps.h.orig	2002-01-02 21:15:27 UTC
+++ sysdeps.h
@@ -25,8 +25,10 @@ extern "C"
 #endif
 
 #ifdef HAVE_VALUES_H
+#if !defined(__FreeBSD__)
 #include <values.h>
 #endif
+#endif
 
 #ifdef HAVE_STRINGS_H
 #include <strings.h>
