--- src/rccstring.h.orig	2009-03-09 13:59:14.000000000 +0100
+++ src/rccstring.h	2009-03-09 13:59:20.000000000 +0100
@@ -18,11 +18,7 @@
 int rccStringFixID(rcc_string string, rcc_context ctx);
 int rccStringChangeID(rcc_string string, rcc_language_id language_id);
 
-#ifdef HAVE_STRNLEN
-# ifndef strnlen
-int strnlen(const char *str, size_t size);
-# endif /* !strnlen */
-#else
+#ifndef HAVE_STRNLEN
 int rccStrnlen(const char *str, size_t size);
 #endif /* HAVE_STRNLEN */
 int rccIsASCII(const char *str);
