--- si-glu/libtess/memalloc.h.orig	Sun Oct  5 20:34:38 2003
+++ si-glu/libtess/memalloc.h	Sun Oct  5 20:35:32 2003
@@ -42,7 +42,7 @@
 #ifndef __memalloc_simple_h_
 #define __memalloc_simple_h_
 
-#if defined(__VMS) || defined(darwin)
+#if defined(__VMS) || defined(darwin) || defined(__FreeBSD__)
 # include <stdlib.h>
 #else
 # include <malloc.h>
