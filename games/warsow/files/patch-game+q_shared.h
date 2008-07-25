--- game/q_shared.h.orig	2008-07-24 05:38:24.000000000 +0700
+++ game/q_shared.h	2008-07-24 05:41:08.000000000 +0700
@@ -98,15 +98,15 @@
 #ifdef _M_IX86
 #if defined __FreeBSD__
 #define CPUSTRING "i386"
-#define ARCH "freebsd_i386"
+#define ARCH "i386"
 #else
 #define CPUSTRING "x86"
 #define ARCH "x86"
 #endif
 #elif defined ( _M_AMD64 )
 #if defined __FreeBSD__
-#define CPUSTRING "x86_64"
-#define ARCH "freebsd_x86_64"
+#define CPUSTRING "amd64"
+#define ARCH "amd64"
 #else
 #define CPUSTRING "x64"
 #define ARCH "x64"
@@ -162,17 +162,12 @@
 #endif
 
 #ifdef __i386__
-#if defined __FreeBSD__
-#define ARCH "freebsd_i386"
-#define CPUSTRING "i386"
-#else
 #define ARCH "i386"
 #define CPUSTRING "i386"
-#endif
-#elif defined ( __x86_64__ )
+#elif defined ( __x86_64__ ) || defined( __amd64__ )
 #if defined __FreeBSD__
-#define ARCH "freebsd_x86_64"
-#define CPUSTRING "x86_64"
+#define ARCH "amd64"
+#define CPUSTRING "amd64"
 #else
 #define ARCH "x86_64"
 #define CPUSTRING "x86_64"
