--- common/platform.h.orig	Sat Feb  9 14:51:05 2002
+++ common/platform.h	Sat Feb  9 14:53:43 2002
@@ -8,8 +8,14 @@
 macintosh
 windows
 playstation
+freebsd
 */
 
+#if defined(__FreeBSD__)
+	#define intel	// what about Alpha version?
+	#define freebsd
+#endif
+
 #if defined(__MWERKS__) // metrowerks
 	#if defined(__INTEL__) // intel
 		#define intel
@@ -64,6 +70,7 @@
 #ifdef windows
 #elif defined(macintosh)
 #elif defined(linux)
+#elif defined(freebsd)
 #else
 #error "Unknown target operating system"
 #endif
