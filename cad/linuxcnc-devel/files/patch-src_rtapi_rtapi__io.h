--- src/rtapi/rtapi_io.h.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/rtapi_io.h
@@ -18,13 +18,14 @@
 
 #include <rtapi.h>
 
+#ifdef __linux__
 #ifdef __KERNEL__
 #include <asm/io.h>
 #elif defined(__i386) || defined(__x86_64)
 #include <sys/io.h>
 #endif
 
-#if defined(__i386) || defined(__x86_64)
+#if (defined(__i386) || defined(__x86_64))
 #define rtapi_inb inb
 #define rtapi_inw inw
 #define rtapi_inl inl
@@ -40,5 +41,6 @@
 #define rtapi_outw(x,y) ((void)0)
 #define rtapi_outl(x,y) ((void)0)
 #endif
+#endif /* !__linux__ */
 
 #endif
