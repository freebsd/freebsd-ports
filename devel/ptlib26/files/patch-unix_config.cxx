--- src/ptlib/unix/config.cxx.orig	2009-04-25 15:12:34.000000000 +0400
+++ src/ptlib/unix/config.cxx	2009-04-25 15:12:52.000000000 +0400
@@ -49,7 +49,7 @@
 #define	EXTENSION		".ini"
 #define	ENVIRONMENT_CONFIG_STR	"/\~~environment~~\/"
 
-#ifdef P_MACOSX
+#if defined(P_MACOSX) || defined(P_FREEBSD)
 #define environ (NULL)
 #endif
 
