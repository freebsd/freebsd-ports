--- xmalloc.h.orig	2015-05-04 09:15:45 UTC
+++ xmalloc.h
@@ -29,7 +29,6 @@ int	 xasprintf(char **, const char *, ..
                 __attribute__((__nonnull__ (2)));
 int	 xsnprintf(char *, size_t, const char *, ...)
 		__attribute__((__format__ (printf, 3, 4)))
-		__attribute__((__nonnull__ (3)))
-		__attribute__((__bounded__ (__string__,1,2)));
+		__attribute__((__nonnull__ (3)));
 
 #endif	/* XMALLOC_H */
