--- trans.h.orig	2015-10-05 23:04:46 UTC
+++ trans.h
@@ -1863,8 +1863,10 @@ extern Expr *new_array_size;
 
 /* Our library omits declarations for these functions! */
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 int link           PP( (char *, char *) );
 int unlink         PP( (char *) );
+#endif
 
 
 
