--- misc/glob.c.orig	2010-07-02 09:52:38.000000000 +0200
+++ misc/glob.c	2010-07-02 09:52:10.000000000 +0200
@@ -903,6 +903,11 @@ prefix_array (const char *dirname, char 
   return 0;
 }
 
+int
+glob_pattern_p (const char *pattern, int quote)
+{
+	return __glob_pattern_p(pattern, quote);
+}
 
 /* We must not compile this function twice.  */
 #if !defined _LIBC || !defined NO_GLOB_PATTERN_P
