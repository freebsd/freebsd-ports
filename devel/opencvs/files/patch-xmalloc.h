--- xmalloc.h.orig	2016-02-06 23:25:26.000000000 +0100
+++ xmalloc.h	2016-02-06 23:33:35.565364000 +0100
@@ -28,7 +28,6 @@ int	 xasprintf(char **, const char *, ..
                 __attribute__((__nonnull__ (2)));
 int	 xsnprintf(char *, size_t, const char *, ...)
 		__attribute__((__format__ (printf, 3, 4)))
-		__attribute__((__nonnull__ (3)))
-		__attribute__((__bounded__ (__string__,1,2)));
+		__attribute__((__nonnull__ (3)));
 
 #endif	/* XMALLOC_H */
