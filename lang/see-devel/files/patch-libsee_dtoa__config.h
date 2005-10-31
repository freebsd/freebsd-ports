--- libsee/dtoa_config.h.orig	Tue Apr 26 13:37:43 2005
+++ libsee/dtoa_config.h	Sat Oct 29 16:07:56 2005
@@ -12,7 +12,7 @@
 
 #include <see/type.h>
 
-#if defined(__i386__) || defined(__amd64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__ia64__) || defined(__alpha__)
 #   define IEEE_8087
 #endif
 
