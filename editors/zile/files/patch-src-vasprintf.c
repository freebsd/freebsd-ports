--- src/vasprintf.c.orig	Wed Nov  2 21:01:32 2005
+++ src/vasprintf.c	Thu Nov  3 01:48:31 2005
@@ -579,7 +579,6 @@
   memcpy (&s.vargs, vargs, sizeof (va_list));
 #endif /* __va_copy */
 #endif /* va_copy */
-  va_copy(s.vargs, vargs);
   s.maxlen = (size_t)INT_MAX;
 
   retval = core(&s);
