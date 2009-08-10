--- ./ksirk/ksirk/iris/src/jdns/jdns_sys.c.orig	2008-12-26 22:45:54.000000000 +0000
+++ ./ksirk/ksirk/iris/src/jdns/jdns_sys.c	2008-12-26 22:45:45.000000000 +0000
@@ -701,7 +701,7 @@
 }
 #endif
 
-#ifdef __res_state_ext
+#ifdef __FreeBSD__
 # define USE_EXTEXT
 #endif
 
