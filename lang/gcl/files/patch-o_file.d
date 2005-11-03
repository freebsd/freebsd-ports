--- o/file.d.orig	Mon Oct 31 13:17:20 2005
+++ o/file.d	Mon Oct 31 13:17:41 2005
@@ -2317,7 +2317,7 @@
 #include <sys/resource.h>
 #include <signal.h>
 
-#if defined(DARWIN)
+#if defined(BSD)
 #define on_exit(a,b)
 #else
 static void
