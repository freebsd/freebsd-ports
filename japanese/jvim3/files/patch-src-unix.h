--- src/unix.h.orig	2013-09-05 04:16:52.000000000 +0900
+++ src/unix.h	2013-09-05 04:18:11.000000000 +0900
@@ -104,7 +104,7 @@
 # define strrchr(ptr, c)		rindex((ptr), (c))
 #endif
 
-#if defined(BSD_UNIX) && !defined(__bsdi__) && !defined(linux) && !defined(__GNU__)
+#if defined(BSD_UNIX) && !defined(__FreeBSD__) && !defined(__bsdi__) && !defined(linux) && !defined(__GNU__)
 # define memset(ptr, c, size)	bsdmemset((ptr), (c), (size))
 char *bsdmemset __ARGS((char *, int, long));
 #endif
