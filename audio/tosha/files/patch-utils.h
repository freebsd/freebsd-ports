--- utils.h.orig	1999-01-01 23:57:51 UTC
+++ utils.h
@@ -63,6 +63,9 @@ void *tmalloc (size_t size);
  *   allocated.
  */
 
+#if defined(__FreeBSD__)  
+#include <osreldate.h>  
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100  
 char *strndup (char *src, int num);
 /*
  *   Like strdup(), but limits the string length to at most
@@ -71,6 +74,8 @@ char *strndup (char *src, int num);
  *   Always allocates <num>+1 bytes, even if less space would
  *   be sufficient to store <src>.
  */
+#endif
+#endif
 
 char *justify (char *str);
 /*
