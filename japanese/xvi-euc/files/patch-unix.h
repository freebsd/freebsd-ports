--- unix.h.OLD	Tue Aug  6 08:18:17 2002
+++ unix.h	Tue Aug  6 08:20:03 2002
@@ -119,7 +119,7 @@
  */
 #if defined(BSD) || defined(BSD386)	/* ken */
 #   include <sys/param.h>
-#   include <sys/dir.h>
+#   include <sys/dirent.h>
 #   include <sys/file.h>	/* get W_OK define for access() */
 #else	/* not BSD */
     /*
