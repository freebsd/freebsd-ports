--- ../setup2/source/custom/jvmsetup/unx/jvmscan.cxx.orig	Wed Aug 14 00:19:33 2002
+++ ../setup2/source/custom/jvmsetup/unx/jvmscan.cxx	Wed Aug 14 00:20:54 2002
@@ -117,7 +117,9 @@
 
 /* some platforms have no hotspot yet even under jdk 1.3 */
 /*  so treat them like classic in JDK 1.2.x  */
-#if defined(POWERPC) && defined(LINUX)
+#if defined(POWERPC) && defined(LINUX) || \
+	defined(INTEL) && defined(FREEBSD)
+
 #define NO_HOTSPOT_USE_CLASSIC 1
 #else 
 #undef NO_HOTSPOT_USE_CLASSIC
