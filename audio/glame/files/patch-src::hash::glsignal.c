--- src/hash/glsignal.c.orig	Wed Mar 24 12:49:38 2004
+++ src/hash/glsignal.c	Wed Mar 24 12:59:16 2004
@@ -35,6 +35,8 @@
 	va_list vax;
 #if defined HAVE_GCC && defined __va_copy
 	__va_copy(vax, va);
+#elif (defined(__FreeBSD__) && __FreeBSD__ >= 5)
+	va_copy(vax, va);
 #elif !(defined OS_BSD && defined CPU_X86 && defined HAVE_GCC)
 	memcpy(vax, va, sizeof(va_list));
 #endif
