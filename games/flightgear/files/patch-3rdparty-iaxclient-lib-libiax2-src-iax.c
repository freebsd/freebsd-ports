--- 3rdparty/iaxclient/lib/libiax2/src/iax.c.orig	2014-03-12 18:16:21.000000000 +0100
+++ 3rdparty/iaxclient/lib/libiax2/src/iax.c	2014-03-12 18:18:38.000000000 +0100
@@ -72,7 +72,7 @@
 #include <arpa/inet.h>
 #include <time.h>
 
-#if !defined(MACOSX) && !defined(__OpenBSD__)
+#if !defined(MACOSX) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #if !defined(SOLARIS)
 #include <error.h>
