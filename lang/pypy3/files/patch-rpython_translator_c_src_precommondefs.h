--- rpython/translator/c/src/precommondefs.h.orig	2016-05-29 20:38:19 UTC
+++ rpython/translator/c/src/precommondefs.h
@@ -20,7 +20,7 @@
 #define _NETBSD_SOURCE 1
 /* Define to activate features from IEEE Stds 1003.1-2001 */
 #ifndef _POSIX_C_SOURCE
-#  define _POSIX_C_SOURCE 200112L
+#  define _POSIX_C_SOURCE 200809L
 #endif
 /* Define on FreeBSD to activate all library features */
 #define __BSD_VISIBLE 1
