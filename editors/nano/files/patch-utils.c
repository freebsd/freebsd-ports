
$FreeBSD$

--- utils.c.orig	Mon Nov 19 03:46:54 2001
+++ utils.c	Tue Dec 18 19:58:04 2001
@@ -47,7 +47,7 @@
     }
 }
 
-
+#ifndef HAVE_STRCASESTR
 /* This is now mutt's version (called mutt_stristr) because it doesn't
    use memory allocation to do a simple search (yuck). */
 char *strcasestr(char *haystack, char *needle)
@@ -69,6 +69,7 @@
     }
     return NULL;
 }
+#endif
 
 char *strstrwrapper(char *haystack, char *needle)
 {
