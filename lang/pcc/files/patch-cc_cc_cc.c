--- cc/cc/cc.c.orig	2014-12-06 09:52:55 UTC
+++ cc/cc/cc.c
@@ -206,7 +206,7 @@ char *cppmdadd[] = CPPMDADD;
 #define PCCLIBDIR	NULL
 #endif
 #ifndef DEFLIBDIRS	/* default library search paths */
-#ifdef MULTIARCH_PATH
+#ifndef MULTIARCH_PATH
 #define DEFLIBDIRS	{ "/usr/lib/", 0 }
 #else
 #define DEFLIBDIRS	{ "/usr/lib/", "/usr/lib/" MULTIARCH_PATH "/", 0 }
