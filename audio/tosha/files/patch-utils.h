--- utils.h.orig	2009-02-24 14:41:21.000000000 +0100
+++ utils.h	2009-02-24 14:42:08.000000000 +0100
@@ -63,6 +63,9 @@
  *   allocated.
  */
 
+#if defined(__FreeBSD__)  
+#include <osreldate.h>  
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100  
 char *strndup (char *src, int num);
 /*
  *   Like strdup(), but limits the string length to at most
@@ -71,6 +74,8 @@
  *   Always allocates <num>+1 bytes, even if less space would
  *   be sufficient to store <src>.
  */
+#endif
+#endif
 
 char *justify (char *str);
 /*
