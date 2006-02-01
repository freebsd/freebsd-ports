--- libsee/dtoa_config.h.orig	Wed Jan 18 13:51:50 2006
+++ libsee/dtoa_config.h	Tue Jan 31 16:52:54 2006
@@ -12,7 +12,7 @@
 
 #include <see/type.h>
 
-#if defined(__i386__) || defined(__amd64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__ia64__) || defined(__alpha__)
 #   define IEEE_8087
 #endif
 
