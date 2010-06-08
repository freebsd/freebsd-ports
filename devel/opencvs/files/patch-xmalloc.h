--- xmalloc.h.orig	2007-01-29 17:22:29.000000000 +0100
+++ xmalloc.h	2010-06-08 20:18:08.000000000 +0200
@@ -29,7 +29,6 @@
                 __attribute__((__nonnull__ (2)));
 int	 xsnprintf(char *, size_t, const char *, ...)
 		__attribute__((__format__ (printf, 3, 4)))
-		__attribute__((__nonnull__ (3)))
-		__attribute__((__bounded__ (__string__,1,2)));
+		__attribute__((__nonnull__ (3)));
 
 #endif	/* XMALLOC_H */
