$FreeBSD$

--- ../../deploy/src/javaws/solaris/native/system_md.h	8 Nov 2004 22:26:54 -0000	1.1.1.1
+++ ../../deploy/src/javaws/solaris/native/system_md.h	5 Oct 2005 17:59:39 -0000
@@ -35,6 +35,23 @@
 #ifdef LINUX
 #define PLATFORM "Linux"
 #define ARCH     "i386"
+#elif _ALLBSD_SOURCE /* LINUX */
+#ifdef __FreeBSD__
+#define PLATFORM "FreeBSD"
+#elif __NetBSD__
+#define PLATFORM "NetBSD"
+#elif __OpenBSD__
+#define PLATFORM "OpenBSD"
+#elif __DragonFly__
+#define PLATFORM "DragonFly"
+#endif
+#ifdef __amd64__
+#define ARCH	"amd64"
+#elif __i386__
+#define ARCH	"i386"
+#else
+#error "Unsupported architecture"
+#endif
 #else /* LINUX */
 #define PLATFORM "SunOS"
 #ifdef __i386
