--- client/defs.h.orig	Fri Sep 27 05:47:14 2002
+++ client/defs.h	Fri Sep 27 05:49:02 2002
@@ -11,7 +11,9 @@
 #endif
 char	*index();
 char	*strsave();
+#ifndef __FreeBSD__
 char	*malloc();
+#endif
 char	*basename();
 char	*expalias();
 
