--- utils/utils.h.orig	2009-02-23 16:51:20.000000000 +0100
+++ utils/utils.h	2009-02-23 16:54:21.000000000 +0100
@@ -42,6 +42,7 @@
  *   allocated.
  */
 
+#if !defined(__FreeBSD__)
 char *strndup (const char *src, int num);
 /*
  *   Like strdup(), but limits the string length to at most
@@ -50,6 +53,7 @@
  *   Always allocates <num>+1 bytes, even if less space would
  *   be sufficient to store <src>.
  */
+#endif
 
 char *justify (char *str);
 /*
