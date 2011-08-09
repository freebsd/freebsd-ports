--- src/i_net.cc.orig	2009-10-19 12:12:43.000000000 +0900
+++ src/i_net.cc	2011-07-29 02:27:29.000000000 +0900
@@ -29,7 +29,7 @@
 
 bool nonet = true;
 
-#ifdef LINUX
+#ifdef __linux__
 #include <linux/if.h>
 #include <linux/sockios.h>
 #endif
