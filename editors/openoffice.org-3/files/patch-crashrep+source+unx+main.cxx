--- ../crashrep/source/unx/main.cxx.orig	Wed Jul  2 23:11:07 2003
+++ ../crashrep/source/unx/main.cxx	Sun Jul 13 11:56:28 2003
@@ -73,7 +73,7 @@
 #include <pwd.h>
 #include <pthread.h>
 
-#ifdef LINUX
+#if defined (LINUX) || (FREEBSD)
 #include <netinet/in.h>
 #endif
 
