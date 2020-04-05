--- slp_platformselect.h.orig	2018-07-23 18:02:45 UTC
+++ slp_platformselect.h
@@ -12,9 +12,9 @@
 #include "platform/switch_amd64_unix.h" /* gcc on amd64 */
 #elif defined(__GNUC__) && defined(__i386__)
 #include "platform/switch_x86_unix.h" /* gcc on X86 */
-#elif defined(__GNUC__) && defined(__powerpc64__) && defined(__linux__)
+#elif defined(__GNUC__) && defined(__powerpc64__) && (defined(__linux__) || defined(__FreeBSD__))
 #include "platform/switch_ppc64_linux.h" /* gcc on PowerPC 64-bit */
-#elif defined(__GNUC__) && defined(__PPC__) && defined(__linux__)
+#elif defined(__GNUC__) && defined(__PPC__) && (defined(__linux__) || defined(__FreeBSD__))
 #include "platform/switch_ppc_linux.h" /* gcc on PowerPC */
 #elif defined(__GNUC__) && defined(__ppc__) && defined(__APPLE__)
 #include "platform/switch_ppc_macosx.h" /* Apple MacOS X on PowerPC */
