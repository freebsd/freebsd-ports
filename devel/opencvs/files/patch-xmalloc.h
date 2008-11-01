--- xmalloc.h	29 Jan 2007 16:22:29 -0000	1.3
+++ xmalloc.h	17 Oct 2008 08:51:46 -0000
@@ -29,7 +29,6 @@
                 __attribute__((__nonnull__ (2)));
 int	 xsnprintf(char *, size_t, const char *, ...)
 		__attribute__((__format__ (printf, 3, 4)))
-		__attribute__((__nonnull__ (3)))
-		__attribute__((__bounded__ (__string__,1,2)));
+		__attribute__((__nonnull__ (3)));
 
 #endif	/* XMALLOC_H */
