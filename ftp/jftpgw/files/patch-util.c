--- util.c~	Sun Feb  3 10:10:54 2002
+++ util.c	Thu Feb 14 22:30:36 2002
@@ -91,6 +91,7 @@
 }
 
 
+#ifndef HAVE_STRCASESTR
 const char* strcasestr(const char* haystack, const char* needle) {
 	char* nhay = strdup(haystack);
 	char* nneed = strdup(needle);
@@ -121,6 +122,7 @@
 
 	return match;
 }
+#endif
 
 
 /* writes a char* to an fd and checks the return value */
