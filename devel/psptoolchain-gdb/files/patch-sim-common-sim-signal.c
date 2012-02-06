--- ./sim/common/sim-signal.c.orig	2011-03-15 03:16:17.000000000 +0000
+++ ./sim/common/sim-signal.c	2012-01-25 22:24:29.000000000 +0000
@@ -27,7 +27,7 @@
    to not think the process has died (so it can be debugged at the point of
    failure).  */
 
-#ifdef _WIN32
+#if defined(_WIN32) && !defined(__CYGWIN__)
 #ifndef SIGTRAP
 #define SIGTRAP 5
 #endif
