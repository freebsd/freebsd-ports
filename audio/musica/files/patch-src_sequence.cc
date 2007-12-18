--- src/sequence.cc.orig	2007-12-18 19:57:14.000000000 +0100
+++ src/sequence.cc	2007-12-18 19:59:18.000000000 +0100
@@ -52,8 +52,10 @@
 
 
 
+#ifdef TIMING_DEBUG
 static long int lastNextTime = 0L;
 static int lastNextTrack = 0;
+#endif
 
 
 
