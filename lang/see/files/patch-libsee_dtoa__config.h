--- libsee/dtoa_config.h.orig	Mon Apr 25 18:19:54 2005
+++ libsee/dtoa_config.h	Mon Apr 25 18:23:28 2005
@@ -12,7 +12,7 @@
 
 #include <see/type.h>
 
-#if defined(__i386__)
+#if defined(__i386__) || defined(__amd64__) || defined(__ia64__) || defined(__alpha__)
 #   define IEEE_8087
 #endif
 
