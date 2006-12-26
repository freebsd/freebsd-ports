--- ./include/q_shared.h.orig	Mon Dec 25 17:07:02 2006
+++ ./include/q_shared.h	Mon Dec 25 17:07:02 2006
@@ -87,7 +87,19 @@
 #define CPUSTRING "Unknown"
 #endif
 
-#elif( defined __sun__ )  /* __linux__ */
+#elif( defined __FreeBSD__ ) /* __linux__ */
+
+#define BUILDSTRING "FreeBSD"
+
+#ifdef __i386__
+#define CPUSTRING "i386"
+#elif defined __alpha__
+#define CPUSTRING "axp"
+#else
+#define CPUSTRING "Unknown"
+#endif
+
+#elif( defined __sun__ )  /* __FreeBSD__ */
 
 #define BUILDSTRING "Solaris"
 
