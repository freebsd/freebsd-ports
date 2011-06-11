--- misc/glob.c.orig	2010-12-03 13:11:57.000000000 +0100
+++ misc/glob.c	2011-03-03 19:12:51.000000000 +0100
@@ -907,6 +907,11 @@ prefix_array (const char *dirname, char 
   return 0;
 }
 
+int
+glob_pattern_p (const char *pattern, int quote)
+{
+	return __glob_pattern_p(pattern, quote);
+}
 
 /* We must not compile this function twice.  */
 #if !defined _LIBC || !defined NO_GLOB_PATTERN_P
