--- src/mesa/main/imports.c.orig	2013-10-05 03:59:22.000000000 +0000
+++ src/mesa/main/imports.c
@@ -566,6 +566,7 @@ float
 _mesa_strtof( const char *s, char **end )
 {
 #if defined(_GNU_SOURCE) && !defined(__CYGWIN__) && !defined(__FreeBSD__) && \
+   !defined(__DragonFly__) && \
    !defined(ANDROID) && !defined(__HAIKU__) && !defined(__UCLIBC__)
    static locale_t loc = NULL;
    if (!loc) {
