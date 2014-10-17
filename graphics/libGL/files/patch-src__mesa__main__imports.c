--- src/mesa/main/imports.c.orig	2014-05-28 09:50:40.000000000 +0200
+++ src/mesa/main/imports.c	2014-05-28 09:50:56.000000000 +0200
@@ -571,7 +571,7 @@
 {
 #if defined(_GNU_SOURCE) && !defined(__CYGWIN__) && !defined(__FreeBSD__) && \
    !defined(ANDROID) && !defined(__HAIKU__) && !defined(__UCLIBC__) && \
-   !defined(__NetBSD__)
+   !defined(__DragonFly__) && !defined(__NetBSD__)
    static locale_t loc = NULL;
    if (!loc) {
       loc = newlocale(LC_CTYPE_MASK, "C", NULL);
