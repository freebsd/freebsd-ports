--- utils.h.orig	2009-02-24 14:08:58.000000000 +0100
+++ utils.h	2009-02-24 14:07:43.000000000 +0100
@@ -65,6 +65,9 @@
  *   allocated.
  */
 
+#if defined(__FreeBSD__)  
+#include <osreldate.h>  
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100  
 char *strndup (const char *src, int num);
 /*
  *   Like strdup(), but limits the string length to at most
@@ -73,6 +76,8 @@
  *   Always allocates <num>+1 bytes, even if less space would
  *   be sufficient to store <src>.
  */
+#endif
+#endif
 
 char *justify (char *str);
 /*
