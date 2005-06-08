--- include/IceUtil/Config.h.orig	Thu Jul 22 01:21:08 2004
+++ include/IceUtil/Config.h	Tue Jul 27 16:16:48 2004
@@ -16,7 +16,7 @@
 // Most CPUs support only one endianness, with the notable exceptions
 // of Itanium (IA64) and MIPS.
 //
-#if defined(__i386) || defined(_M_IX86) || defined (__x86_64)
+#if defined(__i386) || defined(_M_IX86) || defined (__x86_64) || defined(__alpha__)
 #   define ICE_LITTLE_ENDIAN
 #elif defined(__sparc) || defined(__sparc__) || defined(__hppa) || defined(__ppc__) || defined(_ARCH_COM)
 #   define ICE_BIG_ENDIAN
