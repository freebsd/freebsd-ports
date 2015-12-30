--- externs.h.orig	1995-04-15 22:46:14 UTC
+++ externs.h
@@ -5,7 +5,9 @@
 #include <X11/Xresource.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 
 #ifdef NEED_NETINET_IN
 #include <netinet/in.h>
