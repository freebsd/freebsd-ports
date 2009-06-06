--- plugins/org.eclipse.core.net/natives/unix/getproxygnome.c.orig	2009-02-15 19:43:28.612859430 -0500
+++ plugins/org.eclipse.core.net/natives/unix/getproxygnome.c	2009-02-15 19:43:50.402949790 -0500
@@ -16,7 +16,7 @@
 #include <gconf/gconf-value.h>
 #include <gconf/gconf-client.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined (__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
