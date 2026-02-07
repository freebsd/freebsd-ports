--- netdata.cc.orig	2021-07-02 16:20:01 UTC
+++ netdata.cc
@@ -18,7 +18,7 @@
 // ----------------------------------------------------------------------------
 
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <machine/endian.h>
 #else
 #include <endian.h>
