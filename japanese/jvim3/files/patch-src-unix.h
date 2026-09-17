--- src/unix.h.orig	2025-12-15 09:04:17 UTC
+++ src/unix.h
@@ -104,7 +104,7 @@ extern void bcopy __ARGS((char *, char *, int));
 # define strrchr(ptr, c)		rindex((ptr), (c))
 #endif
 
-#if defined(BSD_UNIX) && !defined(__bsdi__) && !defined(linux) && !defined(__GNU__)
+#if defined(BSD_UNIX) && !defined(__FreeBSD__) && !defined(__bsdi__) && !defined(linux) && !defined(__GNU__)
 # define memset(ptr, c, size)	bsdmemset((ptr), (c), (size))
 char *bsdmemset __ARGS((char *, int, long));
 #endif
